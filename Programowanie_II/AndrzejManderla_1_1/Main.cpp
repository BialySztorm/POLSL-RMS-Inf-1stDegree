#include <iostream>
#include "Copy.h"



int main() {
    std::cout << "Class without copy:\n";

    WithoutCopy obj1;
    WithoutCopy obj2 = obj1;
    std::cout << "Address of obj1 pointer: " << obj1.ptr << " Number: " << *(obj1.ptr) << std::endl;
    std::cout << "Address of obj2 pointer: " << obj2.ptr << " Number: " << *(obj2.ptr) << std::endl;

    std::cout << "Class with copy:\n";

    WithCopy obj3;
    WithCopy obj4 = obj3;
    std::cout << "Address of obj1 pointer: " << obj3.ptr << " Number: " << *(obj3.ptr) << std::endl;
    std::cout << "Address of obj2 pointer: " << obj4.ptr << " Number: " << *(obj4.ptr) << std::endl;


    return 0;
}