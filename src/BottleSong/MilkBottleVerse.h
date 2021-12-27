/** @brief Declaration of Milk Bottle Verse class*/

#ifndef MILK_BOTTLE_VERSE_H
#define MILK_BOTTLE_VERSE_H
#include <cstdint>
#include <iostream>
#include <memory>
#include "VerseTemplate.h"

/** @brief This abstract class creates the interface for a song like 99 Bottles of Milk*/
class MilkBottleVerse: public VerseTemplate
{
    public:
        /** @brief Get a new BottleNumber0 object
         * @return std::unique_ptr<VerseTemplate>*/
        static std::unique_ptr<VerseTemplate> CreateMethod ();

//law of demeter changes
        // @brief Default Constructor*/
        MilkBottleVerse() {}; 
        /** @brief Return the verse lyric for the given number
         * @param[in] uint16_t - Verse Number
         * @returns std::string*/ 
        std::string lyric(uint16_t);
    private:
        uint16_t uiVerseNumber;
};

#endif