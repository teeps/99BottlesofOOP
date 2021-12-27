/** @brief Implementation of a VerseTemplate method which allows self-registering of sub-classes
 * @version 0.01 20/12/21
 */
#include "VerseTemplateFactory.h"
#include <iostream>

#include "BeerBottleVerse.h"
#include "MilkBottleVerse.h"

//-------------------
//Register the factory members - this is application specific code, collected here as the least ugly solution
static VerseTemplateFactory * pNewFactory = VerseTemplateFactory::Instance();
std::map<std::string , VerseTemplateFactory::CreateMethod> VerseTemplateFactory::CreationMethods; //Must be defined before registering the CreateMethods
//std::unique_ptr<BottleNumber> (* BottleNumber::pFactory)(uint16_t) = &(pNewFactory->Create);
static bool MilkRegistered = VerseTemplateFactory::Register("Milk",MilkBottleVerse::CreateMethod);
//static bool b1Registered = VerseTemplateFactory::Register(1,BottleNumber1::CreateMethod);
//static bool b6Registered = VerseTemplateFactory::Register(6,BottleNumber6::CreateMethod);  
//-------------------

bool VerseTemplateFactory::Register(const std::string & IndexString, CreateMethod Creator)
{
    if (auto it = CreationMethods.find(IndexString); it ==CreationMethods.end())
    {
        CreationMethods.insert(std::pair<std::string,CreateMethod>(IndexString,Creator));
        return true;
    }
    return false;
};

VerseTemplateFactory* VerseTemplateFactory::pInstance = nullptr;

VerseTemplateFactory* VerseTemplateFactory::Instance()
{
    if (pInstance==nullptr)
    {   
        pInstance = new VerseTemplateFactory;
    } 
    return pInstance;
}

std::unique_ptr<VerseTemplate> VerseTemplateFactory::Create (const std::string & IndexString)
{
    if (auto it = CreationMethods.find(IndexString); it != CreationMethods.end())
    {
        return it->second(); //Call the CreateMethod
    }
    return std::make_unique<BeerBottleVerse>(BeerBottleVerse());
}
