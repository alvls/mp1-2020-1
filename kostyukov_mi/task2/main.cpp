#include <iostream>
#include "Vector.h"

int main()
{
    int x[] = {1, 2, 3};
    Vector<int> v1(x, 3);
    Vector<int> v2(x, 3);
    std::cout<<v1<<std::endl;
    //v1.setSize(6);
    std::cout<<v1 * v2<<std::endl;
    return 0;
}