#problem14.rb

def collatz(n)
  store = n 
  count = 0
  while n>1
    count += 1
    if n%2 == 0 
      n /= 2
    else
      n = 3*n+1
    end
  end
  return [count, store]
end


zeecount=[0,0]
for i in 1_000_000.downto(1) 
  a = collatz(i)
  if a[0] > zeecount[0]
    zeecount = a
  end
end
  
puts zeecount
 
 
