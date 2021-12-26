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
        /** @brief Factory method to produce BottleNumber subclasses*/
        static std::unique_ptr<BottleNumber> For(const uint16_t uiNew);
        /** Can't have a virtual function in the base class for this as it has to be static in the sub-classes.  This means the sub classes all differ in interface
         * from the base class, which seems wrong.  Perhaps it would be an idea to have the sub-classes also inherit from some other abstract class that defines the 
         * CreateMethod?
        */
        //virtual std::unique_ptr<BottleNumber> CreateMethod();
        /** @brief The CreateMethod is included here but deleted*/
        static std::unique_ptr<BottleNumber> CreateMethod() = delete;
        
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
        /** @brief function pointer to factory method for dependency injection.
         * 
         * This static variable must be initialised in code elsewhere*/
        static std::unique_ptr<BottleNumber> (* pFactory)(uint16_t);
};

#endif
