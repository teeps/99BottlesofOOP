/** @brief Declaration of Song class*/

#ifndef Song_H
#define Song_H
#include <cstdint>
#include <iostream>
#include <memory>
#include "versetemplate.h"
#include "BottleNumber.h"
#include "BottleNumberFactory.h"




/** @brief This class creates the 99 bottles song
 * @todo replace naked pointers with unique_ptr etc.
*/
class Song
{
    public:
        /** @brief Default Constructor, defaults to standard 99 bottles of beer song*/
        Song();
        /** @brief Constructor with arguments
         * @param[in] const std::weak_ptr<VerseTemplate> - Verse template
         * @param[in] uint16_t - max verses
         * @param[in] uint16_t - min verses
         */
        Song(const std::weak_ptr<VerseTemplate>, uint16_t uiMax = 100, uint16_t uiMin =0);
        /** @brief Constructor with arguments
         * @param[in] const std::shared_ptr<VerseTemplate> - Verse template
         * @param[in] uint16_t - max verses
         * @param[in] uint16_t - min verses
         */
        Song(const std::shared_ptr<VerseTemplate>, uint16_t uiMax = 100, uint16_t uiMin =0);
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
};

#endif
