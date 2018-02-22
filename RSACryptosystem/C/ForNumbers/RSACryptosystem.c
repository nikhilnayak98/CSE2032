/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - RSA Cryptosystem for numbers ONLY.
*/
#include <stdio.h>
#include <math.h>
double gcd(double, double);
double phi(double);
double generate_public_key(double, double);
double generate_private_key(double, double);
double encrypt(double, double, double);
double decrypt(double, double, double);
int calculate_digits(int);

void main()
{
	double message, p, q, n, phi_of_n, public_key, private_key, encrypted, decrypted;
	
	printf("\nEnter message to encrypt - ");
	scanf("%lf", &message);
	printf("\nEnter two prime numbers :- ");
	printf("\nEnter p - ");
	scanf("%lf", &p);
	printf("\nEnter q - ");
	scanf("%lf", &q);
	
	n = p * q;
	phi_of_n = phi(p) * phi(q);

	public_key = generate_public_key(n, phi_of_n);
	private_key = generate_private_key(public_key, phi_of_n);
	
	encrypted = encrypt(message, public_key, n);
	decrypted = decrypt(encrypted, private_key, n);
	
	printf("\nPublic Key - %.0f", public_key);
	printf("\nPrivate Key - %.0f", private_key);
	printf("\nEncrypted - %.0f", encrypted);
	printf("\nDecrypted - %.0f\n", decrypted);
}

double generate_public_key(double n, double phi_of_n)
{
	double e = calculate_digits((int)n);
	while(e < phi_of_n)
	{
		if(gcd(e, phi_of_n) == 1)
			break;
		e++;
	}
	return e; 
}

double generate_private_key(double e, double phi_of_n)
{
	double d = 2;
	while(1)
	{
		if(fmod((e * d), phi_of_n) == 1)
			return d;
		d++;
	}
	return 0;
}

double encrypt(double x, double e, double n)
{
	double c;
	c = pow(x, e);
	c = fmod(c, n);
	return c;
}

double decrypt(double c, double d, double n)
{
	double x;
	x = pow(c, d);
	x = fmod(x, n);
	return x;
}

double gcd(double a, double b) 
{
    if(b == 0)
        return a;
    return gcd(b, fmod(a, b));
}

double phi(double n)
{
	return (n - 1);
}

int calculate_digits(int n)
{
	int ctr = 0;
	while(n > 0)
	{
		ctr++;
		n /= 10;
	}
	return ctr;
}
