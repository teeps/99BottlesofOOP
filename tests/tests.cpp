/** @brief Catch2 tests for 99 Bottles Song Class
*/

#include "catch.hpp"
#include "../src/BottleSong/BottleSong.h"
#include "../src/BottleSong/BottleNumberFactory.h"
#include <string>
using namespace Catch::Matchers;
TEST_CASE ( "BottleSong") 
{
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

TEST_CASE("Factory")
{
  SECTION ("RegistrationAndCreation")
  {
    /* REQUIRE(BottleNumberFactory::Register(0,BottleNumber0::CreateMethod));
    REQUIRE(BottleNumberFactory::Register(1,BottleNumber1::CreateMethod));
    REQUIRE(BottleNumberFactory::Register(6,BottleNumber6::CreateMethod));
    REQUIRE(BottleNumberFactory::Register(6,BottleNumber6::CreateMethod)==0);  //Second time can't be added */

    std::unique_ptr<BottleNumber> Bottle99 = BottleNumberFactory::Create(99);
    REQUIRE (Bottle99 != nullptr);
    const char* expect99 = "99 bottles";
    REQUIRE_THAT(Bottle99->str(), Equals(expect99));

    std::unique_ptr<BottleNumber> Bottle0 = BottleNumberFactory::Create(0);
    REQUIRE (Bottle0 != nullptr);
    const char* expect0 = "no more bottles";
    REQUIRE_THAT(Bottle0->str(), Equals(expect0));

    std::unique_ptr<BottleNumber> Bottle1 = BottleNumberFactory::Create(1);
    REQUIRE (Bottle1 != nullptr);
    const char* expect1 = "1 bottle";
    REQUIRE_THAT(Bottle1->str(), Equals(expect1));

    std::unique_ptr<BottleNumber> Bottle6 = BottleNumberFactory::Create(6);
    REQUIRE (Bottle6 != nullptr);
    const char* expect6 = "1 six-pack";
    REQUIRE_THAT(Bottle6->str(), Equals(expect6));

  }
}