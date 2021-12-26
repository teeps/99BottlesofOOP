/** @brief Implementation of a BottleNumberFactory method which allows self-registering of sub-classes
 * @version 0.01 20/12/21
 */
//#define DEBUG_FACTORY
#include "BottleNumberFactory.h"
#include <iostream>

#include "BottleNumber0.h"
#include "BottleNumber1.h"
#include "BottleNumber6.h"

//-------------------
//Register the factory members - this is application specific code, collected here as the least ugly solution
static BottleNumberFactory * pNewFactory = BottleNumberFactory::Instance();
std::map<uint16_t , BottleNumberFactory::CreateMethod> BottleNumberFactory::CreationMethods; //Must be defined before registering the CreateMethods
std::unique_ptr<BottleNumber> (* BottleNumber::pFactory)(uint16_t) = &(pNewFactory->Create);
static bool b0Registered = BottleNumberFactory::Register(0,BottleNumber0::CreateMethod);
static bool b1Registered = BottleNumberFactory::Register(1,BottleNumber1::CreateMethod);
static bool b6Registered = BottleNumberFactory::Register(6,BottleNumber6::CreateMethod);  
//-------------------

bool BottleNumberFactory::Register(const uint16_t uiClassNumber, CreateMethod Creator)
{
    if (auto it = CreationMethods.find(uiClassNumber); it ==CreationMethods.end())
    {
#ifdef DEBUG_FACTORY
        std::cout << "Creating registration for map index " << uiClassNumber << std::endl;
#endif     
        CreationMethods.insert(std::pair<uint16_t,CreateMethod>(uiClassNumber,Creator));
#ifdef DEBUG_FACTORY
        std::cout << "Created registration for map index " << uiClassNumber << std::endl;
        std::cout << CreationMethods.size() << std::endl;
#endif
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
    if (auto it = CreationMethods.find(uiNewNumber); it != CreationMethods.end())
    {
        return it->second(); //Call the CreateMethod
    }
    return std::make_unique<BottleNumber>(BottleNumber(uiNewNumber));
}
