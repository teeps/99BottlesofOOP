/** @brief Stream Capitaliser*/

#include "Capitaliser.h"

Capitaliser::Capitaliser ()
{}

std::ostream& operator<< (std::ostream& o, const Capitaliser& capitaliser)
{
    return o << capitaliser.content;
}   
std::stringstream& operator<< (std::stringstream& s, const Capitaliser& capitaliser)
{
    s << capitaliser.content;
    return s;
}  

std::ostream& Capitaliser::operator<< (std::ostream &o)
{
    std::stringstream ss;
    ss << o.rdbuf(); 
    content = ss.str();
    content[0] = std::toupper(content[0]);
    return o;
}

std::ostream& Capitaliser::operator<< (std::string &s)
{
    content = s;
    content[0] = std::toupper(content[0]);
    std::stringstream o;
    return o << content;
}