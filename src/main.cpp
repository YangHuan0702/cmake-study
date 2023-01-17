#include <iostream>
#include "../myfunc/myfunc.h"

int main(){
    std::cout << "Hello CMake \n" << std::endl;
    std::cout << "myfunc : " << myfunc(2,2) << std::endl;
}