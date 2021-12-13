/** @brief Implementation of 99 Bottles Song as in Sandi Metz's book.
 * 
 * @version 0.01 First commit, already coded as far as the end of chapter 4
 * @version 0.02 Added BottleNumber class (chapter 5)
 * @version 0.03 Experimented with Capitaliser class of iostream, ultimately abandoned.
 * @version 0.04 Removed Data Clumps, made successor return a new BottleNumber.  Up to Chapter 6.2
 * 
 * @todo Remove Data Clumps
 * @todo Make Successor return a BottleNumber, not a plain number
 * @todo Implement 'six-pack' functionality
 * @todo Add tests for BottleNumber class
 */
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

/** @brief Capitalise the first letter of a string
 * @param[in] std::string - source
 * @returns std::string
 */

static std::string Capitalise (std::string const text)
{
    std::string RetVal = text;
    RetVal.front() = toupper(RetVal.front());
    return RetVal;
}

std::string BottleSong::verse(uint16_t uiVerse)
{
    std::stringstream sOutput;
    BottleNumber bottleNumber(uiVerse);
    //BottleNumber nextBottle(bottleNumber.uiSuccessor());
    //Verse lines
    sOutput << Capitalise (bottleNumber.str()) << " of beer on the wall, " << bottleNumber.str() << " of beer.\n";
    sOutput << bottleNumber.Action() << bottleNumber.Successor().str() << " of beer." << std::endl;
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

uint16_t BottleNumber::uiSuccessor() const
{
    return uiNumber == 0 ? uiMaxVerse : uiNumber - 1;
}

std::string BottleNumber::Quantity() const //const here says the function does not change BottleNumber?
{
    std::string RetString = (uiNumber == 0 ? "no more" : std::to_string(uiNumber));
    return RetString;
}

std::string BottleNumber::Container () const
{
    return std::string(uiNumber == 1 ? "bottle" : "bottles");
}

std::ostream& operator << (std::ostream& o, const BottleNumber bottlenumber)
{
    return o << bottlenumber.Quantity() << " " << bottlenumber.Container();
}

std::string BottleNumber::str() const
{
    std::stringstream ss;
    ss << Quantity() << " " << Container();
    return ss.str();
}

std::string BottleNumber::Action() const
{
    std::string RetVal;
    if (uiNumber==0)
    {
        RetVal = "Go to the store and buy some more, ";
    } else
    {
        RetVal = "Take " +Pronoun() + " down and pass it around, ";
    }
    return RetVal;
}

std::string BottleNumber::Pronoun() const
{
    return std::string(uiNumber== 1 ? "it" : "one");
}

BottleNumber BottleNumber::Successor () const
{
    return BottleNumber(uiNumber == 0 ? 99 : uiNumber -1);
}