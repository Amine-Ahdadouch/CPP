#pragma once

#include <ostream>
#include <iostream>
#include <initializer_list>

#include "config.h"
using namespace std;

class Vector
{
public:
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;

    Vector(){
        for(value i = 0; i < NDIM; i++)
        {
            vect[i] = 0;
        }
    };
    Vector(initializer_list<value> li)
    {
        value count = 0;
        for (value element : li) {
            vect[count] = element;
            ++count;
        }
    };
    const value& operator[](size_t pos) const;
    value& operator[](size_t pos);
    Vector& operator+=(const Vector& rhs);
    Vector& operator+=(value scalar);
    Vector& operator-=(const Vector& rhs);
    Vector& operator*=(const Vector& rhs);
    Vector& operator*=(const value& scalar);

private:
    value vect[NDIM];
};

ostream& operator<<(ostream& os, const Vector& rhs);
Vector operator+(const Vector& lhs, const Vector& rhs);
Vector operator-(const Vector& lhs, const Vector& rhs);
Vector operator*(const Vector& lhs, value scalar);
Vector operator*(value scalar, const Vector& rhs);
value operator*(const Vector& lhs, const Vector& rhs);