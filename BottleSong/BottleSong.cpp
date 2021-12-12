/** @brief Implementation of 99 Bottles Song as in Sandi Metz's book.
 * 
 * @version 0.01 First commit, already coded as far as the end of chapter 4
 * @version 0.02 Added BottleNumber class (chapter 5)
 * @version 0.03 Experimented with Capitaliser class of iostream, ultimately abandoned.
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
    //Encapsulating this call in getQuantity allows a different verse number to be used (e.g. in the successor lines).  
    //If we called Quantity directly from verse this would be a problem, we'd probably end up with a 'SuccessorQuantity' method.
    return BottleNumber(uiIndex).Quantity();
}

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
    return BottleNumber(uiIndex).uiSuccessor();  //Create an immutable Bottlenumber, then call its uiSuccessor method and return the result.
}

std::string BottleSong::verse(uint16_t uiVerse)
{
    std::stringstream sOutput;
    
    //First line
    sOutput << Capitalise (getQuantity(uiVerse)) << " "<< getContainer (uiVerse) << " of beer on the wall, ";
    sOutput << getQuantity(uiVerse) << " " << getContainer (uiVerse) << " of beer.\n";
    //Last line
    sOutput << getAction(uiVerse) << getQuantity (getSuccessor(uiVerse)) << " " << getContainer(getSuccessor(uiVerse)) << " of beer.\n";
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

std::string BottleNumber::Quantity(uint16_t uiIndex) const //const here says the function does not change BottleNumber?
{
    std::string RetString = (uiNumber == 0 ? "no more" : std::to_string(uiNumber));
    return RetString;
}

std::string BottleNumber::Container (uint16_t uiIndx) const
{
    return std::string(uiNumber == 1 ? "bottle" : "bottles");
}

std::ostream& operator << (std::ostream& o, const BottleNumber bottlenumber)
{
    return o << bottlenumber.Quantity() << " " << bottlenumber.Container();
}