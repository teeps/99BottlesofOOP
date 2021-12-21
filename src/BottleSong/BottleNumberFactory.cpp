/** @brief Implementation of a BottleNumberFactory method which allows self-registering of sub-classes
 * @version 0.01 20/12/21
 */

#include "BottleNumberFactory.h"
#include <iostream>
#define DEBUG_FACTORY

std::map<uint16_t , BottleNumberFactory::CreateMethod> BottleNumberFactory::CreationMethods;

bool BottleNumberFactory::Register(const uint16_t uiClassNumber, CreateMethod Creator)
{
    std::cout << CreationMethods.size() << std::endl;
    if (auto it = CreationMethods.find(uiClassNumber); it ==CreationMethods.end())
    {
#ifdef DEBUG_FACTORY
        std::cout << "Creating registration for map index " << uiClassNumber << std::endl;
#endif     
        CreationMethods.insert(std::pair<uint16_t,CreateMethod>(uiClassNumber,Creator));
        //CreationMethods[uiClassNumber] = Creator;
        std::cout << "Created registration for map index " << uiClassNumber << std::endl;
        std::cout << CreationMethods.size() << std::endl;
        return true;
    }
    return false;
};

BottleNumberFactory* BottleNumberFactory::pInstance = nullptr;

BottleNumberFactory* BottleNumberFactory::Instance()
{
    if (pInstance==nullptr)
    {   
        pInstance = new BottleNumberFactory;
    } 
    return pInstance;
}

std::unique_ptr<BottleNumber> BottleNumberFactory::Create (const uint16_t uiNewNumber)
{
    //CreateMethod method = BottleNumber(uiNewNumber);
    if (auto it = CreationMethods.find(uiNewNumber); it != CreationMethods.end())
    {
        return it->second(); //Call the CreateMethod
    }
    return std::unique_ptr<BottleNumber> (new BottleNumber(uiNewNumber));
}
