#problem17.rb

#this don't work for textmate bundle 1.8.7, gotta run it in the terminal

def a(str)
  case
  when str == "0"
    return ""
  when str == "1"
    return 'one'
  when str == "2"
    return 'two'
  when str == "3"
    return 'three'
  when str == "4"
    return 'four'
  when str == "5"
    return 'five'
  when str == "6"
    return 'six'
  when str == "7"
    return 'seven'
  when str == "8"
    return 'eight'
  when str == "9"
    return 'nine'
  end
end

def b(str)
  case
  when str == '0'
    return 'ten'
  when str == "1"
    return 'eleven'
  when str == "2"
    return 'twelve'
  when str == "3"
    return 'thirteen'
  when str == "4"
    return 'fourteen'
  when str == "5"
    return 'fifteen'
  when str == "6"
    return 'sixteen'
  when str == "7"
    return 'seventeen'
  when str == "8"
    return 'eighteen'
  when str == "9"
    return 'nineteen'
  end
end

def c(str)
  case
  when str == '0' 
    return ''
  when str == '1'
    return 'ten'
  when str == '2'
    return 'twenty'
  when str == "3"
    return 'thirty'
  when str == "4"
    return 'forty'
  when str == "5"
    return 'fifty'
  when str == "6"
    return 'sixty'
  when str == "7"
    return 'seventy'
  when str == "8"
    return 'eighty'
  when str == "9"
    return 'ninety'
  end
end

def d()
  return 'hundred'
end

def e()
  return 'thousand'
end

def f()
  return 'and'
end

def g_d(n, d)
  return n.to_s[-d]
end

def num_to_eng(n)
  if n < 10
    return a(g_d(n,1))
  elsif n < 20
    return b(g_d(n,1))
  elsif n < 100
    if n % 10 == 0
      return c(g_d(n,2))
    else
      return c(g_d(n, 2))+a(g_d(n,1))
    end
  elsif n < 1000
    if n % 100 == 0
      return a(g_d(n, 3))+d()
    elsif n % 10 == 0
      return a(g_d(n,3))+d()+f()+c(g_d(n,2))
    else
      if n%100>20
        return a(g_d(n,3))+d()+f()+c(g_d(n,2))+a(g_d(n,1))
      elsif n%100>9
        return a(g_d(n,3))+d()+f()+b(g_d(n,1))
      else
        return a(g_d(n,3))+d()+f()+a(g_d(n,1))
      end
    end
  else
    return 'onethousand'
  end
end


# puts num_to_eng(10)
# puts num_to_eng(87)
# puts num_to_eng(100)
# puts num_to_eng(111)

# range = (1..1000)
# 
# range1 = (1..10)
# 
range2 = (1..1000)

strr = ''
for i in range2
  strr += num_to_eng(i)
end

puts strr.length




