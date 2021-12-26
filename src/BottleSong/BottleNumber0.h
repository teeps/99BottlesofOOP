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
        BottleNumber0() : uiNumber(0),uiMaxVerse(99) {};
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
        std::string Action() const;
        /** @brief Get the successor BottleNumber for the second line
         * @return std::unique_ptr<BottleNumber*/
        std::unique_ptr<BottleNumber> Successor () const;
        /** @brief Get a new BottleNumber0 object
         * @return std::unique_ptr<BottleNumber>*/
        static std::unique_ptr<BottleNumber> CreateMethod ();
    private:
        uint16_t uiNumber, uiMaxVerse;
};

#endif
