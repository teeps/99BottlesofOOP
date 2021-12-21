/** @brief Declaration of BottleNumber1 class*/

#ifndef BottleNumber1_H
#define BottleNumber1_H
#include <cstdint>
#include <iostream>
#include <memory>
#include "BottleNumber.h"

/** @brief Specific BottleNumber class for number = 1*/
class BottleNumber1 : public BottleNumber {
    public:
        /** @brief Constructor
         * @param[in] uint16_t - the number of this instance*/
        BottleNumber1 ();
        /** @brief Return a string with the song's proper pronoun (it or one) for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return Pronoun string 
        */
        std::string Pronoun() const;
        /** @brief Return a string with the proper container type for a given number.
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return Container string 
        */
        std::string Container() const;
        /** @brief Get a new BottleNumber0 object
         * @return std::unique_ptr<BottleNumber>*/
        static std::unique_ptr<BottleNumber> CreateMethod ();
};

#endif
