#problem26.rb
# 
# 2.upto(100) do |x|
#   if (1.0/x).to_s.length > 15
#     puts 1.0/x
#   end
# end



#key problem, how to calculate decimal expansions of fractions to arbitrary lengths


$remainders = Array.new
def long_division(n, d)
  #(1) Initialize Variables
  quotient = ''
  numer = n.to_s
  denom = d.to_s
  i = 0
  j = 1
  
  #(2) Determine the proper slice of the numerator
  #add zeros to numer as necessary
  until denom.to_i <= numer[i,j].to_i
    if n < d
      numer += '0'
    end
    j += 1
  end

  #(3) Determine the correct multiplier (and assign it as a digit in the quotient)
  quotient += ((numer[i,j].to_i)/(denom.to_i)).to_s

  #(4) Calucate the remainder
  remainder = numer[i,j].to_i - (quotient.to_i*denom.to_i)
  
  #(5) check if remainders have repeated
  if $remainders.include?(remainder)
    return quotient 
  end
  $remainders << remainder
  
  #(6) Recurse if remainder is non-zero
  if remainder == 0
    return quotient
  end
  return quotient+long_division(remainder,d)
end


# puts long_division(1,900)

biggest = [0,0]

1.upto(1000) do |x| 
  a = long_division(1,x)
  $remainders.clear
  if a.length > biggest[0]
    biggest = [a.length, x]
  end
end

puts biggest[1]

# puts long_division(1,936)
# 
# $remainders.clear
# puts
# 
# 
# puts long_division(1,937)
# 
# $remainders.clear
# puts
# 
# puts long_division(1,938)





# 1.upto(20) {|i| puts long_division(2, i)}

# #calculating the remainder & quotient
# quotient += ((numer[i,j].to_i)/(denom.to_i)).to_s
# #subtraction step:
# r = numer[i,j].to_i * 10**j - quotient[i].to_i * denom.to_i * 10**j
# $remainders << r
# 
# 
# #continue if remainder != 0 or if no loop has been found
# if r == 0 or $remainders.length > denominator
#   return quotient
# end
# return quotient + long_division(r, d)
# #storing remainders
# while true
#   if (numerator[i,j].to_i) % (denominator.to_i) != 0
#     remainders << (numerator[i,j].to_i) % (denominator.to_i)
#     #how should i and j be indexed?
#   
#     #next step needed here:
#     quotient += ((numerator[i,j].to_i)/(denominator.to_i)).to_s
#   else
#     return quotient
#   end
# end
  