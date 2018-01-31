/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Euler's Phi Function
*/
#include "stdio.h"
#include "math.h"
int phi(int);
void main()
{
	int n;
	printf("\nEnter a number - ");
	scanf("%d", &n);
	printf("phi of %d = %d\n", n, phi(n));
}

int phi(int n)
{
	int pi;
	double res = n;
	
	for(pi = 2; pi <= sqrt(n); pi++)
	{
		if(n % pi == 0)
		{
			while(n % pi == 0)
			{
				n /= pi;
			}
			res = res * (1.0 - 1.0 / (double)pi);
		}
	}

	if(n > 1)
		res = res * (1.0 - 1.0 / n);
	
	return (int)res;
}
