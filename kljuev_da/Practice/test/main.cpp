#pragma once
#include "Vector.h"

using namespace std;
int main()
{
	cout << "not error\n";
    Vector *V1 = new Vector[10];
    delete[] V1;
	return 0;
}