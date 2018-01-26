/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Chinese Remainder Theorem
*/
#include "stdio.h"
int gcd(int, int);
void main() 
{
    int y, b, c, m, n;

    printf("\nx ≅ b(mod m)");
    
    printf("\nEnter b - ");
    scanf("%d", &b);
    
    printf("\nEnter m - ");
    scanf("%d", &m);
    
    printf("\nx ≅ c(mod n)");
    
    printf("\nEnter c - ");
    scanf("%d", &c);
    
    printf("\nEnter n - ");
    scanf("%d", &n);
    
    if(gcd(m, n) == 1)
    {
    	for(y = 0; y < n; y++)
    	{
    		if((m * y) % n == (c - b))
    			printf("\nx ≅ %d(mod %d)\n", y, n);
    	}
    }
}

int gcd(int a, int b) 
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}
