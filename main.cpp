#include <iostream>
#include "massive.h"



int main()
{
    //Commentary
    Massive<char> Mass(5);
    Mass.SetAll();
    Mass.Print();
    Mass.Inception_sort();
    Mass.Print();
    return 0;
}
