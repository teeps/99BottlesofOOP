/** @brief Implementation of 99 Bottles Song as in Sandi Metz's book.
 * 
 * @version 0.01 First commit, already coded as far as the end of chapter 4
 * @version 0.02 Added BottleNumber class (chapter 5)
 * @version 0.03 Experimented with Capitaliser class of iostream, ultimately abandoned.
 * @version 0.04 Removed Data Clumps, made successor return a new BottleNumber.  Up to Chapter 6.2
 * @version 0.05 Implemented BottleNumber Factory
 * @version 0.06 Moved Factory within BottleNumber class
 * @version 0.07 Removed the conditional from Factory and made it a singleton to avoid issues with static variable initialisation order.  
 * Split classes to separate files. 
 * @todo Add tests for BottleNumber class
 */
#include "BottleSong.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

//Register with the factory

BottleSong::BottleSong ()
{
    /*Register the sub-classes in the factory.  This has to be done after Instancing the Factory to avoid the problem with undefined initialisation 
     *order of statics.  Once Instanced the rest of the code can happily use the static methods.
     *What happens if multiple BottleSongs are created though?  Well, the BottleNumberFactory will only register them the first time, so as long as
     there's not some other class which is going to make use of the Factory this registration is OK here.  Still feels wrong though as it is not really 
     the song's job to do this.  So, these lines are moved to application code for now, e.g. in some sort of init sequence*/ 
    //BottleNumberFactory * pFactory = BottleNumberFactory::Instance();
    //static bool b0Registered = BottleNumberFactory::Register(0,BottleNumber0::CreateMethod);
    //static bool b1Registered = BottleNumberFactory::Register(1,BottleNumber1::CreateMethod);
    //static bool b6Registered = BottleNumberFactory::Register(6,BottleNumber6::CreateMethod);

};

BottleSong::BottleSong(const char * cuiVerse, uint16_t uiMax, uint16_t uiMin)
{
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
    const std::unique_ptr<BottleNumber> bottleNumber = BottleNumber::For(uiVerse);
    //Verse lines
    sOutput << Capitalise (bottleNumber->str()) << " of beer on the wall, " << bottleNumber->str() << " of beer.\n";
    sOutput << bottleNumber->Action() << bottleNumber->Successor()->str() << " of beer." << std::endl;
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
