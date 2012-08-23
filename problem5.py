##problem 5.py

import sys, math

sys.path.append('/Users/nathanielgentile/Documents/OCW/compsci101/Python')

import factor


t = True
init = 24504480
while t:
    init += 1
    for i in range(20, 0, -1):
        if i == 1:
            t = False
        elif factor.factor(i, init):
            continue
        else:
            break
    

print init


#takes a while
