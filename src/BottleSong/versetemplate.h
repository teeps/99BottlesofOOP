/** @brief Declaration of Generic Verse class*/

#ifndef VerseTemplate_H
#define VerseTemplate_H
#include <cstdint>
#include <iostream>

/** @brief This abstract class creates the interface for a verse class*/
class VerseTemplate
{
    public:
        /** @brief Constructor called with a single parameter, the verse number
         * @param[in] uint16_t - Verse Number
        */
        VerseTemplate(uint16_t) {};
        /** @brief Return the verse lyric for the given number
         * @returns std::string*/ 
        virtual std::string lyric() =0;
    protected:
        /** @brief Default Constructor not allowed*/
        VerseTemplate() {};
};

#endif