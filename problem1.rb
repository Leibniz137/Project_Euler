##problem1.rb

i=0
sum = 0

while i<1000 do
  if i%3 == 0 or i%5 == 0
    sum += i
  end
  i += 1
  puts sum
end

puts sum