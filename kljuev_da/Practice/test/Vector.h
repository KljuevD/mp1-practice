#pragma once
#include "iostream"

class Vector
{
private:
    int size;
    int *elements;
public:
    Vector();
    Vector(Vector&);
    Vector(int _size/* = 10*/);
    Vector(int _size/* = 10*/, int *array/* = NULL*/);
    ~Vector();
    void PrintVector();

    Vector& operator=(Vector);
    Vector operator+(Vector);
    Vector operator-(Vector);
    Vector& operator+();    //unary
    Vector& operator-();    //unary
    Vector operator*(Vector);
    Vector operator/(Vector);
    Vector operator%(Vector);
    Vector& operator++();
    Vector& operator++(int);    //postfix
    Vector& operator--();
    Vector& operator--(int);    //postfix
    bool operator==(Vector);
    bool operator!=(Vector);
    bool operator>(Vector);
    bool operator<(Vector);
    bool operator>=(Vector);
    bool operator<=(Vector);
    Vector operator!();
    Vector operator&&(Vector);
    Vector operator||(Vector);
    Vector operator~();
    Vector operator&();
    Vector operator|(Vector);
    Vector operator^(Vector);
    Vector operator<<(Vector);
    Vector operator>>(Vector);
    Vector operator+=(Vector);
    Vector operator-=(Vector);
    Vector operator*=(Vector);
    Vector operator/=(Vector);
    Vector operator%=(Vector);
    Vector operator&=(Vector);
    Vector operator|=(Vector);
    Vector operator^=(Vector);
    Vector operator<<=(Vector);
    Vector operator>>=(Vector);
    Vector operator[](Vector);
    Vector operator*();
    Vector operator&(Vector);
    Vector& operator->();
    Vector operator->*(Vector);
    Vector operator()(Vector);
    Vector operator,(Vector);
    Vector operatorstatic_cast();
    void* operatornew(int);
    void* operatornew[](size_t);
    Vector operatordelete(int*);
    Vector operatordelete[](void*);
};
wchar_t operator""_w(char);