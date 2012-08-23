#problem22.rb


#sort names into alphabetical order:

file = File.open('/Users/nathanielgentile/Documents/OCW/Project_Euler/Problem22/names.txt')

contents = file.read

contents = contents.scan(/\w+/)

contents.sort!


total = 0

for i in contents
  sum = 0
  i.each_char {|c| sum += (c.ord - 64)}
  sum *= (contents.index(i)+1)
  total += sum
end


puts total