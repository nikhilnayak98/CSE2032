
/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Linear Congruence Solver
*/
#include "stdio.h"
int gcd(int, int);
int check(int[], int);
int evaluate(int[], int[], int);
void main()
{
    int n = 4, i, c[n], m[n];
	
	printf("\nx ≅ c(mod m)\n");
    for(i = 0; i < n; i++)
    {
    	printf("\nEnter c - ");
        scanf("%d", &c[i]);
        
        printf("\nEnter m - ");
        scanf("%d", &m[i]);
        
        printf("\n");
    }
 
    if(!check(m, n))
        printf("\nx ≅ %d \n", evaluate(c, m, n));
    else
        printf("\nNo solutions exist.\n");
}
 
// Chinese Remainder Theorem
int evaluate(int c[], int m[], int n)
{
    int Minv[n], q, r, r1, r2, t, t1, t2, k, total = 1, x = 0;
    
    for(k = 0; k < n; k++)
        total *= m[k];
 
    for(k = 0; k < n; k++)
    {
        r1 = m[k];
        r2 = total / m[k];
        t1 = 0;
        t2 = 1;
 
        while(r2 > 0)
        {
            q = r1 / r2;
            r = r1 - q * r2;
            r1 = r2;
            r2 = r;
 
            t = t1 - q * t2;
            t1 = t2;
            t2 = t;
        }
 
        if(r1 == 1)
            Minv[k] = t1;
 
        if(Minv[k] < 0)
            Minv[k] = Minv[k] + m[k];
    }

    for(k = 0; k < n; k++)
        x += (c[k] * total * Minv[k]) / m[k];
 
    return x;
}
 
int check(int m[], int n)
{
	int x, y;
    for(x = 0; x < n; x++)
    {
        for(y = x + 1; y < n; y++)
            if(gcd(m[x], m[y]) != 1)
                return 1;
    }
    return 0;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
 
    return gcd(b, a % b);
}
