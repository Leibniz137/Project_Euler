//problem28.c++

#include <iostream>
#include <cmath>

int main() {
  int dis_spiral_area = 1002001;
  int diag_sum = 1;
  int count = 0;
  int mod = 2;
  for (int i=2; i<=dis_spiral_area; i++){
    if (i%mod==1) {
      diag_sum += i;
      count++;
      if (count==4){
        mod += 2;
        count = 0;
      }
    }
  }

  std::cout << diag_sum << std::endl;
  return 0;
}