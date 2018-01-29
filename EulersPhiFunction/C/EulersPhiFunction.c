/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Euler's Phi Function
*/
#include "stdio.h"
#include "math.h"
void main()
{
	int n, res, i, temp;
	printf("\nEnter n - ");
	scanf("%d", &n);
	res = n;
	temp = n;
	
	for(i = 2; i <= sqrt(n); i++)
    	{
		if(n % i == 0)
		{
			while(n % i == 0)
			{
				n /= i;
			}
			res -= (res / i);
		}
	}

    if(n > 1)
        res -= (res / n);
        
    printf("\nPhi of %d - %d\n", temp, res);
}
