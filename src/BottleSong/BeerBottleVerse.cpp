
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "BeerBottleVerse.h"
#include "BottleNumber.h"
#include "BottleNumber0.h"
#include "BottleNumber1.h"
#include "BottleNumber6.h"
#include "BottleNumberFactory.h"

static std::string Capitalise (std::string const text)
{
    std::string RetVal = text;
    RetVal.front() = toupper(RetVal.front());
    return RetVal;
}

/* std::string BeerBottleVerse::lyric()
{
    std::stringstream sOutput;
    const std::unique_ptr<BottleNumber> bottleNumber = BottleNumber::For(uiVerseNumber);
    //Verse lines
    sOutput << Capitalise (bottleNumber->str()) << " of beer on the wall, " << bottleNumber->str() << " of beer.\n";
    sOutput << bottleNumber->Action() << bottleNumber->Successor()->str() << " of beer." << std::endl;
    return sOutput.str();
}
 */
std::string BeerBottleVerse::lyric(uint16_t uiVerse)
{
    std::stringstream sOutput;
    const std::unique_ptr<BottleNumber> bottleNumber = BottleNumber::For(uiVerse);
    //Verse lines
    sOutput << Capitalise (bottleNumber->str()) << " of beer on the wall, " << bottleNumber->str() << " of beer.\n";
    sOutput << bottleNumber->Action() << bottleNumber->Successor()->str() << " of beer." << std::endl;
    return sOutput.str();
}