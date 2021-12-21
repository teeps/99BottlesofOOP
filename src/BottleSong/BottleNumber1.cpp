/** @brief Implementation of 99 Bottles Song as in Sandi Metz's book.
 */

#include "BottleNumber1.h"
#include "BottleNumberFactory.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>

std::unique_ptr<BottleNumber> BottleNumber1::CreateMethod()
{
    return std::unique_ptr<BottleNumber>( new BottleNumber1());
}

BottleNumber1::BottleNumber1(/* uint16_t uiNewNumber */)
{
    uiNumber =1;
    uiMaxVerse = 99;
}

std::string BottleNumber1::Pronoun() const
{
    return "it";
}

std::string BottleNumber1::Container () const
{
    return "bottle";
}