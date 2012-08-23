#problem25.py

numcalls = 0
memo = {0:1, 1:1}
def fib(n):
	global numcalls
	numcalls += 1
	global memo
	if n not in memo:
		numcalls += 1
	 	memo[n] = fib(n-2)+fib(n-1)
	return memo[n]



n = 0

while len(str(fib(n))) < 1000:
	n += 1

n += 1
print n