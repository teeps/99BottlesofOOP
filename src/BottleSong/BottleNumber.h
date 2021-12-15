/** @brief Declaration of BottleNumber class*/

#ifndef BottleNumber_H
#define BottleNumber_H
#include <cstdint>
#include <iostream>
#include <memory>

/** @brief This class is used to create immutable instances of BottleNumber, and has methods for getting the appropriate parts of the verse based on the BottleNumber*/
class BottleNumber
{
    public:
        static std::unique_ptr<BottleNumber> For(const uint16_t uiNew);
        
        /** @brief Constructor
         * @param[in] uint16_t - the number of this instance*/
        BottleNumber(uint16_t uiNewNumber) : uiNumber(uiNewNumber), uiMaxVerse(99) {};
        /** @brief Return a string with the proper container type for a given number.
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return Container string 
        */
        virtual std::string Container() const;
        /** @brief Return a string with the song's proper pronoun (it or one) for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return Pronoun string 
        */
        virtual std::string Pronoun() const;
        /** @brief Return a string with the proper quantity (digits or 'No more') for a given number
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return quantity string
        */
        virtual std::string Quantity () const;
        /** @brief Return the correct action (final line) for the given index
         * Moving this into a method rather than a switch statement gives a method which has a single responsiblity and removes the smell of a switch 
         * from the verse method.
         * @return std::string - final line*/
        virtual std::string Action() const;
        /** @brief Get the quantity for the second line
         * Moving this into a method removes the logic from the verse method, and so increases the flexibility for future changes.
         * @return uint16_t - successor quantity*/
        virtual uint16_t uiSuccessor () const;
        /** @brief Get the successor BottleNumber for the second line
         * @return uint16_t - successor quantity*/
        virtual std::unique_ptr<BottleNumber> Successor () const;
        /** @brief << operator - streams quantity followed by container.  This can be use in places where we don't need to capitalise*/
        friend std::ostream& operator << (std::ostream& o, const BottleNumber bottlenumber);
        /** @brief Converts BottleNumber to a string of number followed by container*/
        virtual std::string str() const; 

    protected:
        /** @brief Default Constructor is protected*/
        BottleNumber() {};
        uint16_t uiNumber;
        uint16_t uiMaxVerse;
};

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
         * @return uint16_t - successor quantity*/
        std::unique_ptr<BottleNumber> Successor () const;
    private:
        uint16_t uiNumber, uiMaxVerse;
};

/** @brief Specific BottleNumber class for number = 0*/
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
};

/** @brief Deprecated class, this is now dealt with by BottleNumber::For*/
class BottleNumberFactory
{
    public:
        std::unique_ptr<BottleNumber> BottleNumberFor(const uint16_t uiNumber)
        {
            switch (uiNumber)
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
                    return std::unique_ptr<BottleNumber>( new BottleNumber(uiNumber));
                    break;
                }
            }
        }
};

#endif
