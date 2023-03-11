#include "Derived.h"


int main() {
    A a;
    B b;
    C c;
    int x;
    a.methodA();
    b.methodB();
    c.methodC();

    x = a.a1;
    //x = a.a2;
    //x = a.a3;
    x = b.a1;
    //x = b.a2;
    //x = b.a3;
    x = b.b1;
    //x = b.b2;
    //x = b.b3;
    x = c.a1;
    //x = c.a2;
    //x = c.a3;
    x = c.b1;
    //x = c.b2;
    //x = c.b3;
    x = c.c1;
    //x = c.c2;
    //x = c.c3;


    return 0;
}