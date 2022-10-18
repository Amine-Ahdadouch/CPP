#ifndef vector_hpp
#define vector_hpp

#include <iostream>
#include <ostream>
#include <initializer_list>

#include "config.h"

class Vector
{
    public:
    // DO NOT CHANGE THIS
        Vector(const Vector&) = default;
        Vector& operator=(const Vector&) = default;
        ~Vector() = default;
    //

    // Add suitable constructors
        Vector();
        Vector(std::initializer_list<int> list);
        // possibly more

    // Public Member functions here
    //
        Vector& operator+=(const Vector& rhs);
        Vector& operator+=(int value);

        Vector& operator-=(const Vector& rhs);
        Vector& operator*=(const Vector& rhs);
        Vector& operator*=(const int& value);

        Vector& operator+(const Vector& rhs);
        Vector& operator-(const Vector& rhs);

        int& operator*(const Vector& rhs);

        int& operator[](int rhs);


        // More to go
        int *getValues();

    private:
    // Private Member functions here

    // Member variables are ALWAYS private, and they go here
        int vector[NDIM];
};

// Nonmember function operators go here
std::ostream& operator<<(std::ostream& OsPrint, const Vector& rhs);
Vector operator*(const Vector& rhs, int value);
#endif /* vector_hpp */
