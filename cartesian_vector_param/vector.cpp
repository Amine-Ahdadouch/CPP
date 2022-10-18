#include "vector.hpp"

    Vector::Vector(){
        for (int i = 0; i < NDIM; i++){
            vector[i] = 0;
        }
    }

    Vector::Vector(std::initializer_list<int> list){
        std::initializer_list<int>::iterator il;
        int value = 0;
        for (il = list.begin(); il != list.end(); il++){
            vector[value++] = *il;
        }
    }

    Vector& Vector::operator+=(const Vector& rhs){
        for (int i = 0; i < NDIM; ++i){ 
            vector[i] += rhs.vector[i];
        }
        return *this;
    }

    Vector& Vector::operator+=(int value){
        for (int i = 0; i < NDIM; i++){ 
            vector[i] += value;
        }
        return *this;
    }

    Vector& Vector::operator-=(const Vector& rhs){
        for (int i = 0; i < NDIM; ++i){ 
            vector[i] -= rhs.vector[i];
        }
        return *this;
    }

    Vector& Vector::operator*=(const Vector& rhs){
        for (int i = 0; i < NDIM; i++){ 
            vector[i] *= rhs.vector[i];
        }
        return *this;
    }

    Vector& Vector::operator*=(const int& value){
        for (int i = 0; i < NDIM; i++){ 
            vector[i] *= value;
        }
        return *this;
    }


    Vector& Vector::operator+(const Vector& rhs){
        auto v = Vector{rhs};
        return v += *this;
    }

    Vector& Vector::operator-(const Vector& rhs){
        auto v = Vector{rhs};
        return v -= *this;
    }

    Vector operator*(const Vector& rhs, int value){
        auto v = Vector{rhs};
        int* data = Vector{rhs}.getValues();
        for (int i = 0; i <= NDIM; i++){
            v[i] += (value - 1) * data[i];
        }
        return v;
    }

    int& Vector::operator*(const Vector& rhs){
        auto v = Vector{rhs};
        auto vec = (v *= *this);
        for (int i = 1; i < NDIM; i++){
            *vec.getValues() += vec[i];
        }
        return *vec.getValues();
    }

    int& Vector::operator[](int rhs){
        return vector[rhs];
    }

    std::ostream& operator<<(std::ostream& OsPrint, const Vector& rhs)
    {
        int i = 0;
        OsPrint << "{";
        int* data = Vector{rhs}.getValues();
        while (i < NDIM - 1){
            OsPrint << data[i] << ",";
            i++;
        }
        OsPrint << data[i] << "}";
        return OsPrint;
    }

    int *Vector::getValues(){
        return vector;
    }