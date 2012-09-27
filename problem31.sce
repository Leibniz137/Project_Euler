//a valid program, however it is far too complex to solve for the 200th term!


x = poly(0, 'x')

p = 1/((1-x)*(1-x^2)*(1-x^5)*(1-x^10)*(1-x^20)*(1-x^50)*(1-x^100))

currency = [1,2,5,10,20,50,100]

p = 1

for ex = currency
    p = p * 1/(1-(x^ex))    
end

//dp = derivat(p)
//d2p = derivat(dp)
//d3p = derivat(d2p)
//d4p = derivat(d3p)
//d5p = derivat(d4p)
//d6p = derivat(d5p)

series = horner(p,0) + horner(dp,0)*x + (horner(d2p,0)/factorial(2))*(x^2) + (horner(d3p,0)/factorial(3))*(x^3)

function der = n_order_derivat(n, polyn)
    if (n == 0) then
        der = polyn;
    elseif (n == 1) then
        der = derivat(polyn);
    else
        der = derivat(n_order_derivat((n-1), polyn));
    end
endfunction


function series = maclaurian(n,polyn)
    if (n == 0) then
        series = horner(polyn,0);
    else
        nth_term = n_order_derivat(n, polyn)
        series = (horner(nth_term,0)/factorial(n))*(x^n) + maclaurian((n-1),polyn)
    end
    
endfunction

function term = nth_maclaurian_term(n, polyn)
    if (n == 0) then
        term = horner(polyn, 0);
    else
        nth_term = n_order_derivat(n, polyn)
        term = (horner(nth_term,0)/factorial(n))*(x^n)
    end
endfunction




disp(nth_maclaurian_term(5,p))


