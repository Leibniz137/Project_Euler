#problem15.py

def iterative_factorial(n):
    assert type(n) == int
    assert n >= 0
    ans = n
    if ans < 1:
        return 1
    for i in range(1, n, 1):
        ans *= (n-i)
    return ans

def binomial_coefficient(n, k):
    nfact = iterative_factorial(n)
    kfact = iterative_factorial(k)
    nminusk = int(n)-int(k)
    nminuskfact = iterative_factorial((nminusk))
    return nfact/(kfact*nminuskfact)

    

def routes_through_a_square(sidelength):
    return binomial_coefficient((sidelength*2), sidelength)

print routes_through_a_square(20)

