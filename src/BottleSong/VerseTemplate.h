/** @brief Declaration of Generic Verse class*/

#ifndef VerseTemplate_H
#define VerseTemplate_H
#include <cstdint>
#include <iostream>

/** @brief This abstract class creates the interface for a verse class*/
class VerseTemplate
{
    public:
//Law of demeter changes
        /** @brief Default Constructor allowed*/
        VerseTemplate() {};

        /** @brief Return the verse lyric for the given number
         * @param[in] uint16_t - verse number
         * @returns std::string*/ 
        virtual std::string lyric(uint16_t) {return "template";}/* =0 */;
    protected:
        
};

#endif