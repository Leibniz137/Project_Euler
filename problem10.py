#problem10.py

import sys

sys.path.append('/Users/nathanielgentile/Documents/OCW/compsci101/Python')

import math, is_prime

primelist = is_prime.sieve_of_eratosthenes(2*10**6)

newlist = []
for i in range(len(primelist)):
    if primelist[i]:
        newlist.append(i)

psum = 0

for i in newlist:
    psum += i

print psum
