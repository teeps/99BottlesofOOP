/** @brief Implementation of 99 Bottles Song as in Sandi Metz's book.
 */

#include "BottleNumber6.h"
#include "BottleNumberFactory.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>

BottleNumber6::BottleNumber6(/* uint16_t uiNewNumber */)
{
    uiNumber =6;
    uiMaxVerse = 99;
}

std::string BottleNumber6::Container () const
{
    return "six-pack";
}

std::string BottleNumber6::Quantity () const
{
    return "1";
}

std::unique_ptr<BottleNumber> BottleNumber6::CreateMethod()
{
   return std::unique_ptr<BottleNumber>( new BottleNumber6());
}