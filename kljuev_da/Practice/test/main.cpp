#pragma once
#include "Vector.cpp"

using namespace std;
int main()
{
    Vector *V1 = new Vector[10];
    delete[] V1;
    return 0;
}