/** @brief Implementation of 99 Bottles Song as in Sandi Metz's book.
 */

#include "BottleNumber0.h"
#include "BottleNumberFactory.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>

std::string BottleNumber0::Quantity() const
{
        return "no more";
}

std::unique_ptr<BottleNumber> BottleNumber0::Successor () const
{
    return For(uiMaxVerse);
}

std::string BottleNumber0::Action() const
{
    return "Go to the store and buy some more, ";
}

std::unique_ptr<BottleNumber> BottleNumber0::CreateMethod()
{
    return std::unique_ptr<BottleNumber>( new BottleNumber0());
}

