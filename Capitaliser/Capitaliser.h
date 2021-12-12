#ifndef CAPITALISER_H
#define CAPITALISER_H
#include <iostream>
#include <sstream>

/** @brief class which capitalises string content streamed in to it.
 * 
 * The idea here was that this could be used inline in a std::cout << capitaliser << x << y << std::endl sort of style.
 * However, operator precedence order is undefined in this expression, so this is not a reliable way to operate.  However, this class can 
 * still be used in a two step fashion, e.g.:
 * capitaliser << someString;
 * std::coud << capitaliser
 */ 
class Capitaliser : public std::iostream
{
    public:
        /** @brief Default Constructor*/
        Capitaliser();

        /** @brief Streams out the capitalised version of what was streamed in*/
        friend std::ostream& operator<< (std::ostream& o, const Capitaliser &capitaliser);
        
        /** @brief Streams out the capitalised version of what was streamed in*/
        friend std::stringstream& operator<< (std::stringstream& s, const Capitaliser &capitaliser);
        
        /** @brief Streams in to the Capitaliser from an ostream*/
        std::ostream& operator << (std::ostream &o);

        /** @brief Streams in to the Capitaliser from a string*/
        std::ostream& operator << (std::string &s);
        
        /** @brief Spy class for testing*/
        friend class Capitaliser_Spy;        
    private:
        std::string content;
};

class Capitaliser_Spy
{
    public:
        std::string getContent(Capitaliser &capitaliser) 
        {
            return capitaliser.content;
        }
};

#endif