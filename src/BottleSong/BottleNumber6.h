/** @brief Declaration of BottleNumber6 class*/

#ifndef BottleNumber6_H
#define BottleNumber6_H
#include <cstdint>
#include <iostream>
#include <memory>
#include "BottleNumber.h"

/** @brief Specific BottleNumber class for number = 6*/
class BottleNumber6 : public BottleNumber {
    public:
        /** @brief Constructor
         * @param[in] uint16_t - the number of this instance*/
        BottleNumber6 ();
        /** @brief Return a string with the proper container type for a given number.
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return Container string 
        */
        std::string Container() const;
        /** @brief Return a string with the proper quantity (digits or 'No more') for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return quantity string
        */
        std::string Quantity () const;
        /** @brief Get a new BottleNumber0 object
         * @return std::unique_ptr<BottleNumber>*/
        static std::unique_ptr<BottleNumber> CreateMethod ();
};

#endif
