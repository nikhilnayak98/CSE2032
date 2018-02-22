/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Successive Squaring
*/
#include "stdio.h"
void main()
{
	int a, b = 1, k, m;
	
	printf("\na^k(mod m)");
	
	printf("\nEnter a - ");
	scanf("%d", &a);
	printf("\nEnter k - ");
	scanf("%d", &k);
	printf("\nEnter m - ");
	scanf("%d", &m);
	
	printf("\n%d^%d(mod %d)", a, k, m);
	
	while(k >= 1)
	{
		if((k % 2) != 0)
			b *= a;
		
		a *= a;
		k /= 2;
	}
	printf("\nx - %d\n", b);
}
