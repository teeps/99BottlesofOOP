/** @brief Declaration of Song class*/

#ifndef Song_H
#define Song_H
#include <cstdint>
#include <iostream>
#include <memory>
#include "VerseTemplate.h"

/** @brief This class creates the 99 bottles song
 * @todo replace naked pointers with unique_ptr etc.
*/
class Song
{
    public:
        /** @brief Default Constructor, defaults to standard 99 bottles of beer song*/
        Song() = delete;
        /** @brief Constructor with smart pointer to VerseTemplate
         * @param[in] std::shared_ptr<VerseTemplate>
        */
        Song(std::shared_ptr<VerseTemplate> pTemplate) {pVerseTemplate = pTemplate;};
        /** @brief Return a verse for the given index
         * @param[in] uint16_t - verse number
         * @return std::string
         */
        std::string verse (uint16_t);

        /** @brief Return verses between the given indices
         * @param[in] uint16_t - higher verse number
         * @param[in] uint16_t - lower verse number
         * @return std::string
         */
        std::string verses (uint16_t,uint16_t);
    private:
        /** @brief Smart pointer for a VerseTemplate*/
        std::shared_ptr<VerseTemplate> pVerseTemplate;
};

#endif
