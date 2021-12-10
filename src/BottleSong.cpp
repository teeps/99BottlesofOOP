#include "BottleSong.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

BottleSong::BottleSong ()
{
 VerseTemplate = std::string("");
 bStandardVerse = true;
 uiMaxVerse = 99;
 uiMinVerse = 0;
};

BottleSong::BottleSong(const char * cuiVerse, uint16_t uiMax, uint16_t uiMin)
{
    VerseTemplate = std::string(cuiVerse);
    bStandardVerse = false;
    uiMaxVerse = uiMax;
    uiMinVerse = uiMin;
};

std::string BottleSong::getContainer(uint16_t uiIndex = 2)
{
    return std::string(uiIndex == 1 ? "bottle" : "bottles");
}

std::string BottleSong::getPronoun(uint16_t uiIndex = 2)
{
    return std::string(uiIndex == 1 ? "it" : "one");
}

std::string BottleSong::getQuantity (uint16_t uiIndex)
{
    //Maybe this is not perfect from a single responsibility principal point of view - the method is dealing with the content *and* the capitalisation.
    std::string RetString = (uiIndex == 0 ? "no more" : std::to_string(uiIndex));
    return RetString;
}

static std::string Capitalise (std::string text)
{
    std::string RetVal = text;
    RetVal.front() = toupper(RetVal.front());
    return RetVal;
}

std::string BottleSong::getAction(uint16_t uiIndex)
{
    std::string RetVal;
    if (uiIndex==0)
    {
        RetVal = "Go to the store and buy some more, ";
    } else
    {
        RetVal = "Take " + getPronoun (uiIndex) + " down and pass it around, ";
    }
    return RetVal;
}
uint16_t BottleSong::getSuccessor(uint16_t uiIndex)
{
    return uiIndex == 0 ? uiMaxVerse : uiIndex - 1;
}

std::string BottleSong::verse(uint16_t uiVerse)
{
    std::stringstream sOutput;
    BottleNumber botnum(uiVerse);
    //First line
    sOutput << Capitalise (getQuantity (uiVerse)) << " "<< getContainer (uiVerse) << " of beer on the wall, ";
    sOutput << getQuantity (uiVerse) << " " << getContainer (uiVerse) << " of beer.\n";
    //Last line
    sOutput << getAction(uiVerse) << getQuantity (botnum.uiSuccessor()) << " " << getContainer(botnum.uiSuccessor()) << " of beer.\n";
    return sOutput.str();
}

std::string BottleSong::verses(uint16_t uiHighVerse, uint16_t uiLowVerse)
{
    std::stringstream sOutput;
    sOutput.str("");
    for (uint16_t i=uiHighVerse; i>uiLowVerse; i--)
    {
        sOutput << this->verse(i) << std::endl;
    }
    sOutput << this->verse(uiLowVerse);
    return sOutput.str();
}

BottleNumber::BottleNumber(uint16_t uiNewNumber)
{
    uiNumber = uiNewNumber;
    uiMaxVerse = 99;
}

uint16_t BottleNumber::uiSuccessor()
{
    return uiNumber == 0 ? uiMaxVerse : uiNumber - 1;
}