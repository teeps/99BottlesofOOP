/** @brief Declaration of Beer Bottle Verse class*/

#ifndef BerrBottleVerse_H
#define BerrBottleVerse_H
#include <cstdint>
#include <iostream>
#include "versetemplate.h"

/** @brief This abstract class creates the interface for a song like 99 Bottles of Beer*/
class BeerBottleVerse: protected VerseTemplate
{
    public:
        BeerBottleVerse(uint16_t uiVerseIndex) : uiVerseNumber(uiVerseIndex) {}; 
        /** @brief Return the verse lyric for the given number
         * @param[in] uint16_t - Verse Number
         * @returns std::string*/ 
        std::string Lyric();
    private:
        uint16_t uiVerseNumber;
};

#endif