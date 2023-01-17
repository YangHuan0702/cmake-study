#include <iostream>

#include "config.h"

#ifdef USESUBMODULE
    #include "../myfunc/myfunc.h"
#endif

int main(){
    std::cout << "Hello CMake \n" << std::endl;
    #ifdef USESUBMODULE
        std::cout << "myfunc : " << myfunc(2,2) << std::endl;
    #endif
}