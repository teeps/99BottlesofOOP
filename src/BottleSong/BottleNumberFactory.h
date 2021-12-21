#ifndef BOTTLE_NUMBER_FACTORY_H
#define BOTTLE_NUMBER_FACTORY_H
#include <map>
#include "BottleNumber.h"

/** @brief This external factory class is an attempt at making something to allow classes to self-register
 * With deference to https://www.cppstories.com/2018/02/factory-selfregister/
 * However, there seems to be an issue with initialisation order of static variables across different translation units
 * being undefined, so while the original inspration webpage used a class which was never instantiated (with a private constructor too),
 * this has been written to be instantiated as a singleton to ensure the initialisation order is known.
 * @version 0.01 19/12/21
 * @version 0.02 21/12/21 - 
*/
class BottleNumberFactory
{
    public:
        using CreateMethod = std::unique_ptr<BottleNumber>(*)();

        static BottleNumberFactory* Instance();
        /** @brief Called to register sub-classes
         * @param[in] std::string - Text name of the class
         * @param[in] CreateMethod - Pointer to class's creation method
         * @return bool - true if successful*/
        static bool Register(const uint16_t, CreateMethod);
        /** @brief Factory method to create a new BottleNumber
         * @param[in] uint16_t - Bottle Number of new class
         * @return std::unique_ptr<BottleName> - newly created class*/
        static std::unique_ptr<BottleNumber>  Create (const uint16_t uiClassNumber);
    private:
        static BottleNumberFactory* pInstance; 
        static std::map <uint16_t, CreateMethod> CreationMethods;
};


#endif