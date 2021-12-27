/** @brief Catch2 tests for 99 Bottles Song Class
*/

#include "catch.hpp"
#include "../src/BottleSong/Song.h"
#include "../src/BottleSong/BottleNumberFactory.h"
#include "../src/BottleSong/BottleNumber0.h"
#include "../src/BottleSong/BottleNumber1.h"
#include "../src/BottleSong/BottleNumber6.h"
#include "../src/BottleSong/MilkBottleVerse.h"
#include <string>
using namespace Catch::Matchers;

TEST_CASE ( "BottleSong") 
{
  SECTION( "Song Constructors")
  {
    Song BeerSong = Song();
  }
  SECTION ( "VerseText_2Bottles") 
  {
    const char * expected = "2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer.\n";
    Song song;
    
    REQUIRE_THAT (song.verse(2).c_str(), Equals (expected));
  }

  SECTION ( "VerseText_1Bottles") 
  {
    const char * expected = "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer.\n";
    Song song;;
    
    REQUIRE_THAT (song.verse(1).c_str(), Equals (expected));
  }

  SECTION ( "VerseText_0Bottles") 
  {
    const char * expected = "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer.\n";
    Song song;;
    
    REQUIRE_THAT (song.verse(0).c_str(), Equals (expected));
  }

  SECTION ("Verse Text - 6 Bottles with six-pack requirement")
  {
    const char * expected = "1 six-pack of beer on the wall, 1 six-pack of beer.\nTake one down and pass it around, 5 bottles of beer.\n";
    Song song;;
    
    REQUIRE_THAT (song.verse(6).c_str(), Equals (expected));
  }

  SECTION ("Verse Text - 7 Bottles with six-pack requirement")
  {
    const char * expected = "7 bottles of beer on the wall, 7 bottles of beer.\nTake one down and pass it around, 1 six-pack of beer.\n";
    Song song;;
    
    REQUIRE_THAT (song.verse(7).c_str(), Equals (expected));
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

TEST_CASE ("MilkBottleVerse - Law Of Demeter")
{

  SECTION ( "VerseText_1Bottles") 
  {
    const char * expected = "1 bottle of milk on the wall, 1 bottle of milk.\nTake it down and pass it around, no more bottles of milk.\n";
    MilkBottleVerse Verse;
    Song song=Song(&Verse);
    
    REQUIRE_THAT (song.verse(1).c_str(), Equals (expected));
  }
}