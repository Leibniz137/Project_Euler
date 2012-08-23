#problem6.rb

a = (0..100).to_a

sum = 0
a.each {|x| sum += x}


puts sum**2

#sum**2 = 24502500

sumsquares = 0

a.each {|x| sumsquares += x**2}

puts sumsquares

puts (sum**2 - sumsquares)