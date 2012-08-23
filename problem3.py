#problem3.py

import sys, math

sys.path.append('/Users/nathanielgentile/Documents/OCW/compsci101/Python')

import factor


factlist = []
for i in range(1, int(math.sqrt(600851475143))+1):
    if factor.factor(i, 600851475143):
        factlist.append(i)


print factlist
