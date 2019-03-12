#pragma once
#include "Polynomial.h"
#include "iostream"

using namespace std;
Monomial::Monomial()
{
    value = 0;
    power = 0;
    next = 0;
}

Monomial::Monomial(double v)
{
    value = v;
    power = 0;
    next = 0;
}

Polynomial::Polynomial()
{
    head = 0;
}

Polynomial::Polynomial(Polynomial& tmp)
{
    head = tmp.head;
}

Polynomial Polynomial::Input()
{
    Polynomial tmp;
    cin >> tmp.head->value >> tmp.head->power;
    return tmp;
}

void Polynomial::Output()
{
    return;
}

Polynomial Polynomial::operator+(Polynomial obj)
{
    Polynomial tmp;
    int i = 0;
    if (obj.head->next != 0 || head->next != 0)
    {
        tmp.head->value = head->value + obj.head->value;
        tmp.head->power = i++;
    }
    return tmp;
}

Polynomial Polynomial::operator-(Polynomial obj)
{
    Polynomial tmp;
    return tmp;
}

Polynomial Polynomial::operator*(Polynomial obj)
{
    Polynomial tmp;
    return tmp;
}