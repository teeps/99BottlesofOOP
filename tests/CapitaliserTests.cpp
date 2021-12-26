/** Catch2 tests for Capitaliser Class*/

#include "catch.hpp"
#include "../src/Capitaliser/Capitaliser.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace Catch::Matchers;

TEST_CASE ("Capitaliser can Stream In and Out")
{
    std::string testString="Cow";
    Capitaliser newCap;
    SECTION ("Stream In")
    {
        REQUIRE_NOTHROW (newCap << testString);
        Capitaliser_Spy Spy;
        REQUIRE_THAT (Spy.getContent(newCap), Equals(testString));
    }
    SECTION ("Stream Out")
    {
        REQUIRE_NOTHROW (newCap << testString);
        std::stringstream ss;
        ss<< newCap;
        REQUIRE_THAT(ss.str(), Equals ("Cow"));
    }
    SECTION ("Capitalise In Two Steps")
    {
        testString = "cow dog";
        std::stringstream ss;
        REQUIRE_NOTHROW (newCap << testString);
        REQUIRE_NOTHROW (ss     << newCap);
        REQUIRE_THAT (ss.str(), Equals ("Cow dog"));
    }
}