/** @brief Implementation of 99 Bottles Song as in Sandi Metz's book.
 */

#include "BottleNumber.h"
#include "BottleNumber0.h"
#include "BottleNumber1.h"
#include "BottleNumber6.h"
#include "BottleNumberFactory.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>

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
    return For(uiNumber-1);
}

std::unique_ptr<BottleNumber> BottleNumber::For(const uint16_t uiNew)
{
    BottleNumberFactory *pFactory = BottleNumberFactory::Instance();
    return BottleNumberFactory::Create(uiNew);
    /*switch (uiNew)
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
        case 6:
        {
            return std::unique_ptr<BottleNumber>( new BottleNumber6());
            break;
        }
        default:
        {
            return std::unique_ptr<BottleNumber>( new BottleNumber(uiNew));
            break;
        }
    }*/
}