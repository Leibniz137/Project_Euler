import math


##this works only for integer inputs
def is_pythagorean_triplet(a, b, c):
    if (a**2)+(b**2) == c**2:
        return True
    return False


    #create the set of all numbers a, b, c such that a+b+c=1000
##sset = []
##for i in range(1, 50):
##    for j in range(i, 50):
##        for k in range(j, 50):
##            if is_pythagorean_triplet(i, j, k):
##                sset.append((i,j,k))
##
##
##
##sset2 = []
##for i in range(1,50):
##    for j in range(i+1, 51): #so j>i
##        sset2.append((2*i*k, (j**2)-(i**2), (j**2)+(i**2)))

#these nested loops will give us all of the tuples such that a<b<c
sset = []
for a in range(1000):
    for b in range(a+1, 1000):
        for c in range(b+1, 1000):
            if a+b+c==1000:
                sset.append((a,b,c))
                

            

