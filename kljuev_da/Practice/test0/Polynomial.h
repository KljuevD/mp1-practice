#pragma once

class Monomial
{
public:
    double value;
    double power;
    Monomial* next;
    Monomial();
    Monomial(double);
};
class Polynomial
{
private:
    Monomial* head;
public:
    Polynomial();
    Polynomial(Polynomial&);
    Polynomial Input();
    void Output();
    Polynomial operator+(Polynomial);
    Polynomial operator-(Polynomial);
    Polynomial operator*(Polynomial);
};