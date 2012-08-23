#problem4.rb

#step 1, generate a program that finds palindromes
#step 2: find a way to call it repeatedly and find 99*91



def palindrome(str)
  palin = true
    for i in (0...str.length/2).to_a
      if str[i] != str[-i-1]:
        palin = false
      end
    end
    return palin
end

palinlist = []
for j in (900..999).to_a
  for k in (900..999).to_a
    if palindrome((j*k).to_s)
      palinlist << j*k
    end
  end
end

puts palinlist