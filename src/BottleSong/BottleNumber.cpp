/** @brief Implementation of 99 Bottles Song as in Sandi Metz's book.
 */

#include "BottleNumber.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

uint16_t BottleNumber::uiSuccessor() const
{
    if (uiNumber==0)
    {
        return uiMaxVerse;
    } else
    {
        return uiNumber -1;
    }
}

std::string BottleNumber::Quantity() const //const here says the function does not change BottleNumber?
{
    return std::to_string(uiNumber);
}

std::string BottleNumber::Container () const
{
    return "bottles";
}

std::ostream& operator << (std::ostream& o, const BottleNumber bottlenumber)
{
    return o << bottlenumber.Quantity() << " " << bottlenumber.Container();
}

std::string BottleNumber::str() const
{
    std::stringstream ss;
    ss << Quantity() << " " << Container();
    return ss.str();
}

std::string BottleNumber::Action() const
{
    return "Take " +Pronoun() + " down and pass it around, ";
}

std::string BottleNumber::Pronoun() const
{
    return "one";
}


std::unique_ptr<BottleNumber> BottleNumber::Successor () const
{
    BottleNumberFactory Factory;
    return Factory.BottleNumberFor(uiNumber-1);
}

std::string BottleNumber0::Quantity() const
{
        return "no more";
}

std::unique_ptr<BottleNumber> BottleNumber0::Successor () const
{
    BottleNumberFactory Factory;
    return Factory.BottleNumberFor(uiMaxVerse);
}

std::string BottleNumber0::Action() const
{
    return "Go to the store and buy some more, ";
}

//Pronoun and container not needed for BottleNumber0

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

std::unique_ptr<BottleNumber> BottleNumber::For(const uint16_t uiNew)
{
    switch (uiNew)
    {
        case 0:
        {
            return std::unique_ptr<BottleNumber>( new BottleNumber0());
            break;
        }
        case 1:
        {
            return std::unique_ptr<BottleNumber>( new BottleNumber1());
            break;
        }
        default:
        {
            return std::unique_ptr<BottleNumber>( new BottleNumber(uiNew));
            break;
        }
    }
}