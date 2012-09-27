--problem24.hs

--find the millionth lexicographic permutation of the digits?

--lexicographic order:
--given to ordered sets A & B,
--(a,b)<=(a',b') iff a<a' or (a=a' and b <= b')

--binary:
bin_lexi_order(p1,p2) = ((fst p1)<(fst p2)) || ((fst p1)== (fst p2)) && ((snd p1)<=(snd p2))

--ternary
lst ((a,b,c)) = c

ter_lexi_order(p1,p2) = ((fst p1)<(fst p2)) || ((fst p1)==(fst p2)) && ((snd p1)<=(snd p2)) || ((fst p1)==(fst p2)) && ((snd p1)==(snd p2)) && ((lst p1)<=(lst p2))
