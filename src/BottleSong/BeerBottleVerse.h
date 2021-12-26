/** @brief Declaration of Beer Bottle Verse class*/

#ifndef BEER_BOTTLE_VERSE_H
#define BEER_BOTTLE_VERSE_H
#include <cstdint>
#include <iostream>
#include "VerseTemplate.h"

/** @brief This abstract class creates the interface for a song like 99 Bottles of Beer*/
class BeerBottleVerse: public VerseTemplate
{
    public:
        // @brief Default Constructor with initializer list*/
        BeerBottleVerse(uint16_t uiVerseIndex) : uiVerseNumber(uiVerseIndex) {}; 
        /** @brief Return the verse lyric for the given number
         * @param[in] uint16_t - Verse Number
         * @returns std::string*/ 
        std::string lyric();
    private:
        uint16_t uiVerseNumber;
};

#endif