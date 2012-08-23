#problem2.rb

#step 1, a ruby program that makes the fibonacci sequence

#0,1,1,2,3,5

a = 0
b = 1
fib = 0
fiblist = [0,1]
while fib<4e6
  fib = a + b
  fiblist << fib
  a = b
  b = fib
end


#step 2: write a program that goes through the list of fib #'s
# and tosses out the odds

for i in fiblist
  if i%2 != 0
    fiblist.delete(i)
  end
end

for i in fiblist
  if i%2 != 0
    fiblist.delete(i)
  end
end

#don't get why the second loop is needed but it is!

#step 3: sum the remaining list

fibsum = 0

for i in fiblist
  fibsum += i
end

puts fibsum