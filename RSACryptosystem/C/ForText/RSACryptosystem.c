/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - RSA Cryptosystem for text.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long int generate_public_key(long int);
long int generate_private_key(long int, long int);
long int gcd(long int, long int);
long int isprime(long int);
long int encrypt(char, long int, long int);
char decrypt(long int, long int, long int);
long int phi(long int);
void main()
{
    long int i, len;
    long int p, q, n, phi_of_n, public_key, private_key, encrypted[50];
    char text[50], decrypted[50];

    printf("Enter message: ");
    fgets(text, 20, stdin);
    
    len = strlen(text);
    
    printf("\nEnter p : ");
    scanf("%ld", &p);
    printf("\nEnter q : ");
    scanf("%ld", &q);

    if((isprime(p)) && isprime(q))
    {
    	n = p * q;
    	phi_of_n = phi(p) * phi(q);
    
    	public_key = generate_public_key(phi_of_n);
    	private_key = generate_private_key(public_key, phi_of_n);
    
    	printf("\nn : %ld", n);
    	printf("\nphi(n) : %ld", phi_of_n);
    	printf("\nPublic key : %ld", public_key);
    	printf("\nPrivate key : %ld", private_key);
    
    	for(i = 0; i < len; i++)
        	encrypted[i] = encrypt(text[i], n, public_key);
    	
    	printf("\nEncrypted message: \n");
    	for(i = 0; i < len; i++)
        	printf("%ld", encrypted[i]);
    
    	for(i = 0; i < len; i++)
        	decrypted[i] = decrypt(encrypted[i], n, private_key);
   
    	printf("\nDecrypted message: ");
    	for(i = 0; i < len; i++)
        	printf("%c", decrypted[i]);
	}
	else
		printf("\nEither of p and q is not a prime number.\n");
}

long int generate_public_key(long int phi)
{
	long int e;
	
	do
	{
		e = rand() % phi;
	} while(gcd(phi, e) != 1);
	
	return e;
}

long int generate_private_key(long int e, long int phi)
{
	long int d;
	
	do
	{
		e = rand() % phi;
	} while(gcd(phi, e) != 1);

    return d;
}

long int gcd(long int a, long int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

long int isprime(long int a)
{
    int i;
    for(i = 2; i < a; i++)
    {
        if((a % i) == 0)
            return 0;
    }
    return 1;
}

long int encrypt(char ch, long int n, long int e)
{
    int i;
    long int temp = ch;
    for(i = 1; i < e; i++)
        temp = (temp * ch) % n;
    return temp;
}

char decrypt(long int ch, long int n, long int d)
{
    int i;
    long int temp = ch;
    for(i = 1; i < d; i++)
        ch = (temp * ch) % n;
    return ch;
}

long int phi(long int n)
{
	return (n - 1);
}
