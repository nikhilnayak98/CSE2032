/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - RSA Cryptosystem
*/
#include "stdio.h"
int gcd(int, int);
void main()
{
}

int gcd(int a, int b) 
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}
