/*
Name - Nikhil Ranjan Nayak
Regd No - 1641012040
Desc - Compute intergration of dt/ln(t) from 2 to x, Π(x) and x / ln(x).
 */
#include "stdio.h"
#include "math.h"
double compute_series(double);
int bigpi(double);
int isprime(int);
void main()
{
	double x, lower_bound = compute_series(2);
	
	printf("\nΠ(x)");
	printf("\nx/ln(x)");
	printf("\n[2, x]Sdt/ln(t)\n");
	
	printf("\n10 %5c 10^2 %5c 10^3 %5c 10^4 %5c 10^6", ' ', ' ', ' ', ' ');
	printf("\n%d %7c %d %6c %d %6c %d %5c %d", bigpi(10), ' ', bigpi(100), ' ', bigpi(1000), ' ', bigpi(10000), ' ', bigpi(1000000));
	
	printf("\n%.2f %3c %.2f %3c %.2f %4c %.2f %2c %.2f", (10 / log(10)), ' ', (100 / log(100)), ' ', (1000 / log(1000)), ' ', (10000 / log(10000)), ' ', (1000000 / log(1000000)));
	
	printf("\n%.2f %3c %.2f %4c %.2f %3c %.2f %2c %.2f\n", (compute_series(10) - lower_bound), ' ', (compute_series(100) - lower_bound), ' ', (compute_series(1000) - lower_bound), ' ', (compute_series(10000) - lower_bound), ' ', (compute_series(1000000) - lower_bound));
}

double compute_series(double t)
{	
	double i = 1, sum, term, error = 0.000001;
	
	sum = log(log(t)) + log(t);
	term = log(t);
	
	while(fabs(term) > error)
	{
		i++;
		term = (term * (log(t) / i) * (i - 1)) / i;
		sum += term ;
	}
	
	return sum;
}

int bigpi(double x)
{
	int i, ctr = 0;
	
	if(x >= 2)
		ctr++;
	for(i = 3; i <= x; i += 2)
	{
		if(isprime(i) == 1)
			ctr++;
	}
	return ctr;
}

int isprime(int x)
{
	int i, flag = 1;
	
	for(i = 2; i <= sqrt(x); i++)
	{
		if(x % i == 0)
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}
