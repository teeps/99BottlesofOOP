/** @brief Catch2 tests for 99 Bottles Song Class
*/

#include "catch.hpp"
#include "../src/BottleSong/BottleSong.h"
#include "../src/BottleSong/BottleNumberFactory.h"
#include <string>
using namespace Catch::Matchers;
void vInitFactory()
{
  BottleNumberFactory * pFactory = BottleNumberFactory::Instance();
  static bool b0Registered = BottleNumberFactory::Register(0,BottleNumber0::CreateMethod);
  static bool b1Registered = BottleNumberFactory::Register(1,BottleNumber1::CreateMethod);
  static bool b6Registered = BottleNumberFactory::Register(6,BottleNumber6::CreateMethod);
}
TEST_CASE ( "BottleSong") 
{
  vInitFactory();
  SECTION ("Constructors")
  {
    const char * cVerseTemplate = "This is verse ${number}.\n";
    //No args
    BottleSong SongWithoutArgs();
    BottleSong SongWith1Arg(cVerseTemplate);
    BottleSong SongWith2Args(cVerseTemplate,100);
    BottleSong SongWith3Args(cVerseTemplate,10,0);
  }
  SECTION ( "VerseText_2Bottles") 
  {
    const char * expected = "2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer.\n";
    BottleSong Song;
    
    REQUIRE_THAT (Song.verse(2).c_str(), Equals (expected));
  }

  SECTION ( "VerseText_1Bottles") 
  {
    const char * expected = "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer.\n";
    BottleSong Song;
    
    REQUIRE_THAT (Song.verse(1).c_str(), Equals (expected));
  }

  SECTION ( "VerseText_0Bottles") 
  {
    const char * expected = "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer.\n";
    BottleSong Song;
    
    REQUIRE_THAT (Song.verse(0).c_str(), Equals (expected));
  }

  SECTION ("Verse Text - 6 Bottles with six-pack requirement")
  {
    const char * expected = "1 six-pack of beer on the wall, 1 six-pack of beer.\nTake one down and pass it around, 5 bottles of beer.\n";
    BottleSong Song;
    
    REQUIRE_THAT (Song.verse(6).c_str(), Equals (expected));
  }

  SECTION ("Verse Text - 7 Bottles with six-pack requirement")
  {
    const char * expected = "7 bottles of beer on the wall, 7 bottles of beer.\nTake one down and pass it around, 1 six-pack of beer.\n";
    BottleSong Song;
    
    REQUIRE_THAT (Song.verse(7).c_str(), Equals (expected));
  }
}

TEST_CASE ("BottleNumber")
{
  vInitFactory();
  SECTION ("Six Pack")
  {
    const char * expected = "six-pack";
    BottleNumber6 bottleNumber;
    CHECK_THAT (bottleNumber.Container(), Equals(expected));

    REQUIRE_THAT(bottleNumber.Quantity(), Equals("1"));
  }
  SECTION ("Seven Successor")
  {
    const char * expected = "1 six-pack";
    BottleNumber bottleNumber(7);
    CHECK_THAT (bottleNumber.Successor()->str() , Equals(expected));
  }
  SECTION ("Factory Returns Correct Class")
  {
    std::unique_ptr<BottleNumber> bottleNumber = BottleNumber::For(6);
    REQUIRE_THAT(bottleNumber->Quantity(), Equals ("1") );
  }
}