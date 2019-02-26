#pragma once
#include "Vector.h"

Vector::Vector()
{
    size = 10;
    elements = new int[size];
}
Vector::Vector(int _size, int* _elements)
{
    if (size >= 0 || _elements == NULL)
    {
        size = _size;
        elements = new int[size];
        for (int i = 0; i < size; i++)
            elements[i] = _elements[i];
    }
    else
        std::cout << "error";
}
void Vector::PrintVector()
{
    for (int i = 0; i < size; i++)
        std::cout << elements[i] << std::endl;
}