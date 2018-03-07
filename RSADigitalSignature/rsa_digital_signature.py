# Name - Nikhil Ranjan Nayak
# Regd no - 1641012040
# Desc - RSA Digital Signature

from math import sqrt
from random import shuffle

def exp_mod(a, b, n):
	return (a**b) % n
    
def gcd(a, b):
	if b > a:
		return gcd(b, a)
	if a % b == 0:
		return b
	return gcd(b, a % b)

def gcd_qs(a, b):
	# List of q values from gcd(a, b)
	# >>> gcd(72, 5)
	# [14, 2]
	if b > a:
		a, b = b, a
	assert a > b
	assert gcd(a, b) == 1
	
	rem = None
	while rem != 1:
		q = a // b			# 72 // 5 = 14		5 // 2 = 2
		rem = a - q * b		# 72 - 5*14 = 2		5 - 2*2 = 1
		a = b				# a is now 5		a is now 2
		b = rem				# b is now 2		b is now 1
		yield q
		
def mod_inv(a, n): 
	# Modular inverse
	# >>> inv_mod(72, 5)
	# 29
	t0, t1 = 0, 1
	for q in gcd_qs(a, n):
		t = t0 - q * t1
		t0, t1 = t1, t  # move them all back one space
	return t
	
def is_prime(n):
	return all(n % i != 0 for i in range(2, int(sqrt(n))))
	
if __name__ == '__main__':
	# pick two big prime numbers
	p = 101
	q = 499
	
	assert is_prime(p)
	assert is_prime(q)
	
	n = p * q  # first part of public key
	phi_n = (p-1)*(q-1)
	
	# pick v, second part of public key
	valid_range = list(range(p+1, q))
	shuffle(valid_range)  # shuffles in place
	
	for v in valid_range:       # search for a prime in (p, q)
		if not is_prime(v):     # need v to be prime
			continue
		if gcd(v, phi_n) == 1:  # found one that fits
			break
			
	print('v = ', v)
	
	# compute s
	s = mod_inv(v, phi_n)  # private key
	
	# desired message to send
	msg = 321 
	assert 1 < msg < n
	
	signed_msg = exp_mod(msg, s, n)
	print('signed message = ', signed_msg)
	
	decrypted = exp_mod(signed_msg, v, n)
	print('decrypted message = ', decrypted)
	print('same as original message: ', decrypted == msg)
