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
	int i;
	double res = n;
	
	for(i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0)
		{
			while(n % i == 0)
			{
				n /= i;
			}
			res = res * (1.0 - 1.0 / (double)i);
		}
	}

	if(n > 1)
		res = res * (1.0 - 1.0 / n);
	
	return (int)res;
}
