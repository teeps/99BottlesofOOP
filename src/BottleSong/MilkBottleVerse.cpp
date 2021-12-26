
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "MilkBottleVerse.h"
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

std::string MilkBottleVerse::lyric()
{
    std::stringstream sOutput;
    const std::unique_ptr<BottleNumber> bottleNumber = BottleNumber::For(uiVerseNumber);
    //Verse lines
    sOutput << Capitalise (bottleNumber->str()) << " of milk on the wall, " << bottleNumber->str() << " of milk.\n";
    sOutput << bottleNumber->Action() << bottleNumber->Successor()->str() << " of milk." << std::endl;
    return sOutput.str();
}

std::unique_ptr<VerseTemplate> MilkBottleVerse::CreateMethod(uint16_t uiNumber)
{
    return std::make_unique<MilkBottleVerse> (MilkBottleVerse(uiNumber));
}