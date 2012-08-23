import math

def is_it_prime(n):
    """Tests if a given natural # is prime or composite"""
    assert type(n) == int
    if n<0:
        print "Please enter a natural number"
    elif 0<=n<2:
        print "Trivially not prime and not composite"
    elif n == 2:
        return True
    else:
        count = 2
        while count < math.sqrt(float(n)+1):     ##crucial: count only needs to go to sqrt.n!
            if n%count == 0:
                return False
            else:
                count += 1       
        return True

##primelist = []
##i = 0
##while len(primelist) < 10002:
##    if is_it_prime(i) == True:
##        primelist.append(i)
##
##print primelist[:10]
##print primelist[10000:]
