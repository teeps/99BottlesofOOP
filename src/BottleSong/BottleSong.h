/** @brief Declaration of BottleSong classes*/

#ifndef BottleSong_H
#define BottleSong_H
#include <cstdint>
#include <iostream>
#include <memory>
#include "BottleNumber.h"
#include "BottleNumberFactory.h"
#include "BottleNumber0.h"
#include "BottleNumber1.h"
#include "BottleNumber6.h"

/** @brief This class creates the 99 bottles song*/
class BottleSong 
{
    public:
        /** @brief Default Constructor*/
        BottleSong();
        /** @brief Constructor with arguments
         * @param[in] const char * - Verse template
         * @param[in] uint16_t - max verses
         * @param[in] uint16_t - min verses
         */
        BottleSong(const char *, uint16_t uiMax = 100, uint16_t uiMin =0);
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
