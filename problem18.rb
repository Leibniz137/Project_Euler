#problem18.rb



 arow1 = [75]
 arow2 = [95, 64]
 arow3 = [17, 47, 82]
 arow4 = [18, 35, 87, 10]
 arow5 = [20, 4, 82, 47, 65]
 arow6 = [19, 1, 23, 75, 3, 34]
 arow7 = [88, 2, 77, 73, 7, 63, 67]
 arow8 = [99, 65, 4, 28, 6, 16, 70, 92]
 arow9 = [41, 41, 26, 56, 83, 40, 80, 70, 33]
arow10 = [41, 48, 72, 33, 47, 32, 37, 16, 94, 29]
arow11 = [53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14]
arow12 = [70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57]
arow13 = [91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48]
arow14 = [63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31]
arow15 = [4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23]

row1 = (0...arow1.length).to_a
row2 = (0...arow2.length).to_a
row3 = (0...arow3.length).to_a
row4 = (0...arow4.length).to_a
row5 = (0...arow5.length).to_a
row6 = (0...arow6.length).to_a
row7 = (0...arow7.length).to_a
row8 = (0...arow8.length).to_a
row9 = (0...arow9.length).to_a
row10 = (0...arow10.length).to_a
row11 = (0...arow11.length).to_a
row12 = (0...arow12.length).to_a
row13 = (0...arow13.length).to_a
row14 = (0...arow14.length).to_a
row15 = (0...arow15.length).to_a

triangle = [row1,row2,row3,row4,row5,row6,row7,row8,row9,row10,row11,row12,row13,row14,row15]



greatest = 0
routecount = 0

for a in row1
  for b in row2
    if b <= a+1 and a <= b
      for c in row3
        if c <= b+1 and b <= c
          for d in row4
            if d <= c+1 and c <= d
              for e in row5
                if e <= d+1 and d <= e
                  for f in row6
                    if f <= e+1 and e <= f
                      for g in row7
                        if g <= f+1 and f <= g
                          for h in row8
                            if h <= g+1 and g <= h
                              for i in row9
                                if i <= h+1 and h <= i
                                  for j in row10
                                    if j <= i+1 and i <= j
                                      for k in row11
                                        if k <= j+1 and j <= k
                                          for l in row12
                                            if l <= k+1 and k <= l
                                              for m in row13
                                                if m <= l+1 and l <= m
                                                  for n in row14
                                                    if n <= m+1 and m <= n
                                                      for o in row15
                                                        if o <= n+1 and n <= o
                                                          routecount += 1
                                                          sum = arow1[a]+arow2[b]+arow3[c]+arow4[d]+arow5[e]+arow6[f]+arow7[g]+arow8[h]+arow9[i]+arow10[j]+arow11[k]+arow12[l]+arow13[m]+arow14[n]+arow15[o]
                                                          if sum > greatest
                                                            greatest = sum
                                                          end
                                                        end
                                                      end
                                                    end
                                                  end
                                                end
                                              end
                                            end
                                          end
                                        end
                                      end
                                    end
                                  end
                                end
                              end
                            end
                          end
                        end
                      end
                    end
                  end
                end
              end
            end
          end
        end
      end
    end
  end
end
# 
# puts routecount

# greatest = 0
# routecount = 0

# a1 = [3]
# b1 = [7, 4]
# c1 = [2, 4, 6]
# d1 = [8, 5, 9, 3]
# 
# # e1 = [1, 0, 0, 0, 1]
# 
# # littletriangle = [a,b,c,d]
# 
# a = (0...a1.length).to_a
# b = (0...b1.length).to_a
# c = (0...c1.length).to_a
# d = (0...d1.length).to_a
# 
# 
# # e = (0...e1.length).to_a
# 
# for i in a
#   for j in b
#     if i <= j+1 and i >= j-1
#       for k in c
#         if j <= k+1 and j >= k-1
#           for l in d
#             if k <= l+1 and k>= l-1
#               sum = a1[i]+b1[j]+c1[k]+d1[l]
#               routecount += 1
#               if sum > greatest
#                 greatest = sum
#               end
#             end
#           end
#         end
#       end
#     end
#   end
# end
# 
# 
# 
# 
#     # for k in c
#     #   
#     # 
#     # 
#     #   # for l in d
#     #   # 
#     #   # end
#     # end
# puts routecount
# puts greatest 


# a1 = [3]
# b1 = [7, 4]
# c1 = [2, 4, 6]
# 
# a = (0...a1.length).to_a
# b = (0...b1.length).to_a
# c = (0...c1.length).to_a
# 
# 
# for i in a
#   for j in b
#     if j <= i+1 and j >= i
#       for k in c
#         if k <= j+1 and k >= j
#           # puts i, j, k
#           # puts
#           
# 
#           # puts a1[i]
#           # puts b1[j]
#           # puts c1[k]
#           # puts
#           # 
#           sum = a1[i]+b1[j]+c1[k]
#           routecount += 1
#           if sum > greatest
#             greatest = sum
#           end
#         end
#       end
#     end
#   end
# end


puts greatest









                            