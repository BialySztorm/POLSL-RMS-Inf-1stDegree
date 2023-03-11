#include "Copy.h"

WithoutCopy::WithoutCopy()
{
    ptr = new int;
    *ptr = 5;
}

WithCopy::WithCopy()
{
    ptr = new int;
    *ptr = 5;
}

WithCopy::WithCopy(const WithCopy& other)
{
    ptr = new int;
    *ptr = *(other.ptr);
}

WithCopy::~WithCopy()
{
    delete ptr;
}
