#problem12.rb

#triangle numbers = n(n+1)/2 = "n+1 choose 2"

def factors(n)
  2.upto(n) do |x|
    if n % x == 0
      return [x]+factors(n/x)
    end
  end
  return [n,1]
end



def nth_trinum(n)
  return n*(n+1)/2
end

def num_divisors(x)
  primefacts = factors(x)
  primefacts.delete(1)
  a = primefacts.uniq()
  b = Array.new
  a.each {|y| b << primefacts.count(y)}
  num_divisors = 1
  b.each {|z| num_divisors *= (z+1)}
  return num_divisors
end
  
n = 1
while num_divisors(nth_trinum(n)) < 500
  n += 1
end

puts n

puts nth_trinum(n)

puts num_divisors(nth_trinum(n))








