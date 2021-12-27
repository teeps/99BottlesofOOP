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
        Song();
        /** @brief Constructor with verse template string
         * @param[in] const char * - text matching somehting in the factory
        */
        Song(const char *);
        /** @brief Constructor with lyric function pointer
         * @param[in] std::string (*)(uint16_t)
        */
        //Song(std::shared_ptr<std::string (*)(uint16_t)> pfLyricFunction) {pfLyric = pfLyricFunction;};
        Song(VerseTemplate* pfTemplate) {pfVerseTemplate = pfTemplate;};
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
        void vPrintVerseType(){std::cout<<VerseType<<std::endl;}
    private:
        /** @brief Function pointer for verse template constructor*/ 
        VerseTemplate* (* pfVerse)(uint16_t);
        /** @brief Function pointer for some lyric method*/
//        std::shared_ptr<std::string (*)(uint16_t)> pfLyric;
        VerseTemplate * pfVerseTemplate;
        std::string VerseType;
};

#endif
