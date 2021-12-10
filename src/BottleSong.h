#ifndef BottleSong_H
#define BottleSong_H
#include <cstdint>
#include <iostream>
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
        std::string VerseTemplate;
        bool bStandardVerse;
        uint16_t uiMaxVerse;
        uint16_t uiMinVerse;
        /** @brief Return a string with the proper container type for a given number.
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @param[in] uint16_t - index of verse
         * @return Container string 
        */
        std::string getContainer(uint16_t);
        /** @brief Return a string with the song's proper pronoun (it or one) for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @param[in] uint16_t - index of verse
         * @return Pronoun string 
        */
        std::string getPronoun(uint16_t);
        /** @brief Return a string with the proper quantity (digits or 'No more') for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @param[in] uint16_t - Verse index
         * @return quantity string
        */
        std::string getQuantity(uint16_t);
        /** @brief Return the correct action (final line) for the given index
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @param[in] uint16_t - Verse Index
         * @return std::string - final line*/
        std::string getAction(uint16_t);
        /** @brief Get the quantity for the second line
         * Moving this into a method removes the logic from the verse method, and so increases the flexibility for future changes.
         * @param[in] uint16_t - current quantity
         * @return uint16_t - successor quantity*/
        uint16_t getSuccessor (uint16_t);
};

/** @brief This class is used to create immutable instances of BottleNumber, and has methods for getting the appropriate parts of the verse based on the BottleNumber*/
class BottleNumber
{
    public:
        /** @brief Constructor
         * @param[in] uint16_t - the number of this instance*/
        BottleNumber (uint16_t);
        /** @brief Return a string with the proper container type for a given number.
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @param[in] uint16_t - index of verse
         * @return Container string 
        */
        std::string Container(uint16_t);
        /** @brief Return a string with the song's proper pronoun (it or one) for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @param[in] uint16_t - index of verse
         * @return Pronoun string 
        */
        std::string Pronoun(uint16_t);
        /** @brief Return a string with the proper quantity (digits or 'No more') for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @param[in] uint16_t - Verse index
         * @return quantity string
        */
        std::string Quantity(uint16_t uiIndex=1);
        /** @brief Return the correct action (final line) for the given index
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @param[in] uint16_t - Verse Index
         * @return std::string - final line*/
        std::string Action(uint16_t);
        /** @brief Get the quantity for the second line
         * Moving this into a method removes the logic from the verse method, and so increases the flexibility for future changes.
         * @param[in] uint16_t - current quantity
         * @return uint16_t - successor quantity*/
        uint16_t uiSuccessor ();

    private:
        /** @brief Default Constructor is private*/
        BottleNumber() {};
        uint16_t uiNumber;
        uint16_t uiMaxVerse;
};

#endif
