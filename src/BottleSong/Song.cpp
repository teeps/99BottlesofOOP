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
 * @version 0.08 Resolved question of how and where to initialise the factory with least ugliness.  This is now performed in BottleNumberFactory.cpp,
 * so all the application specific initialisation of the factory is in the one place at the top of that file.  Rather than being hard-coded, the factory method 
 * is now given to the BottleNumber class via a static function pointer, so the BottleNumber class is no longer dependent on that factory class, rather it has 
 * dependency injection.  The setting up of that function pointer is also handled in BottleNumberFactory.cpp, so there is no code within BottleNumber.h or cpp
 * other than the code directly required for that class. 
 * @version 0.09 Corrected some code comments
 * @todo Add tests for BottleNumber class
 * @todo Add a factory for verse templates
 */
#include "Song.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "BeerBottleVerse.h"
#include "VerseTemplateFactory.h"

Song::Song ()
{
    /*Register the sub-classes in the factory.  This has to be done after Instancing the Factory to avoid the problem with undefined initialisation 
     *order of statics.  Once Instanced the rest of the code can happily use the static methods.
     *What happens if multiple Songs are created though?  Well, the BottleNumberFactory will only register them the first time, so as long as
     there's not some other class which is going to make use of the Factory this registration is OK here.  Still feels wrong though as it is not really 
     the song's job to do this.  So, these lines are moved to application code for now, e.g. in some sort of init sequence*/ 
    //std::shared_ptr<BottleNumberFactory> pFactory = std::make_shared<BottleNumberFactory>(BottleNumberFactory());
    VerseType="";  
};

Song::Song (const char * pVerseType)
{
    VerseType = std::string(pVerseType);
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

std::string Song::verse(uint16_t uiVerse)
{
    std::stringstream sOutput;
    std::unique_ptr<VerseTemplate> pNewVerse = VerseTemplateFactory::Create(VerseType,uiVerse); //Factory allows for different lyrics
    return pNewVerse->lyric();
}

std::string Song::verses(uint16_t uiHighVerse, uint16_t uiLowVerse)
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
