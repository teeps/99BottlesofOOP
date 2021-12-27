#ifndef VERSE_TEMPLATE_FACTORY_H
#define VERSE_TEMPLATE_FACTORY_H
#include "VerseTemplate.h"
#include <memory>
#include <map>

/** @brief Factory class which allows for different verse types to be produced*/
class VerseTemplateFactory
{
    public:
        using CreateMethod = std::unique_ptr<VerseTemplate>(*)();
        /** @brief Return a pointer to the instance of BottleNumberFactory*/
        static VerseTemplateFactory* Instance();
        /** @brief Called to register sub-classes by identifying string
         * @param[in] std::string & - Index number of the sub-class
         * @param[in] CreateMethod - Pointer to class's creation method
         * @return bool - true if successful*/
        static bool Register(const std::string &, CreateMethod);
        /** @brief Factory method to create a new VerseTemplate for a given index string
         * 
         * If no specific subclass exists for the given string the default BeerBottleVerse class will be returned. 
         * @param[in] std::string & - Index string of new class
         * @return std::unique_ptr<VerseTemplate> - newly created class*/
        static std::unique_ptr<VerseTemplate>  Create (const std::string &);
    private:
        static VerseTemplateFactory* pInstance; 
        /** @brief Map of CreateMethods against index numbers*/
        static std::map <std::string, CreateMethod> CreationMethods;

};

#endif