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
    Vector(int _size = 10);
    Vector(int _size = 10, int *array = NULL);
    ~Vector();
    void PrintVector();
};