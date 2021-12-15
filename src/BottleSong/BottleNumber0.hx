/** @brief Declaration of BottleNumber0 class*/

#ifndef BottleNumber0_H
#define BottleNumber0_H
#include <cstdint>
#include <iostream>
#include <memory>
#include "BottleNumber.h"

/** @brief Specific BottleNumber class for number = 0*/
class BottleNumber0 : public BottleNumber {
    public:
        /** @brief Constructor
         * @param[in] uint16_t - the number of this instance*/
        BottleNumber0 (uint16_t);
        /** @brief Return a string with the proper container type for a given number.
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return Container string 
        */
//        std::string Container() const;
        /** @brief Return a string with the song's proper pronoun (it or one) for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return Pronoun string 
        */
//        std::string Pronoun() const;
        /** @brief Return a string with the proper quantity (digits or 'No more') for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return quantity string
        */
        std::string Quantity () const;
        /** @brief Return the correct action (final line) for the given index
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return std::string - final line*/
//        std::string Action() const;
        /** @brief Get the quantity for the second line
         * Moving this into a method removes the logic from the verse method, and so increases the flexibility for future changes.
         * @return uint16_t - successor quantity*/
//        uint16_t uiSuccessor () const;
        /** @brief Get the successor BottleNumber for the second line
         * @return uint16_t - successor quantity*/
        BottleNumber Successor () const;
        /** @brief << operator - streams quantity followed by container.  This can be use in places where we don't need to capitalise*/
//        friend std::ostream& operator << (std::ostream& o, const BottleNumber bottlenumber);
        /** @brief Converts BottleNumber to a string of number followed by container*/
//        std::string str() const; 
    private:
        /** @brief Default Constructor is private*/
//        BottleNumber0();
//        uint16_t uiNumber;
//        uint16_t uiMaxVerse;
};

#endif
