/** Catch2 tests for 99 Bottles Song Class*/

#include "catch.hpp"
#include "../src/BottleSong.h"
#include <string>

TEST_CASE ( "Constructors") 
{
  const char * cVerseTemplate = "This is verse ${number}.\n";
  //No args
  BottleSong SongWithoutArgs();
  BottleSong SongWith1Arg(cVerseTemplate);
  BottleSong SongWith2Args(cVerseTemplate,100);
  BottleSong SongWith3Args(cVerseTemplate,10,0);
};
using namespace Catch::Matchers;


TEST_CASE ( "VerseText_2Bottles") 
{
  const char * expected = "2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer.\n";
  BottleSong Song;
  
  REQUIRE_THAT (Song.verse(2).c_str(), Equals (expected));
};

TEST_CASE ( "VerseText_1Bottles") 
{
  const char * expected = "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer.\n";
  BottleSong Song;
  
  REQUIRE_THAT (Song.verse(1).c_str(), Equals (expected));
};

TEST_CASE ( "VerseText_0Bottles") 
{
  const char * expected = "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer.\n";
  BottleSong Song;
  
  REQUIRE_THAT (Song.verse(0).c_str(), Equals (expected));
};

