#PProblem13.rb



file = File.open('/Users/nathanielgentile/Documents/OCW/Project_Euler/fifty100intlist.txt')

contents = file.read

contentsarray = Array.new

contents.each_line {|x| contentsarray << x}

intarray = contentsarray.map(&:to_i)

sum = 0

intarray.each {|x| sum += x}


puts sum