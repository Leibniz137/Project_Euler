//problem30.c++

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  bool got_one = false;
  int sum = -1;
  for (int i=0; i<10; i++){
    for (int j=0; j<10; j++){
      for (int k=0; k<10; k++){
        for (int l=0; l<10; l++){
          for (int m=0; m<10; m++){
            for (int n=0; n<10; n++){
              double i_d = i;
              double j_d = j;
              double k_d = k;
              double l_d = l;
              double m_d = m;
              double n_d = n;
              int s_o_cu = (pow(i_d, 5)+pow(j_d,5)+pow(k_d,5)+pow(l_d,5)+pow(m_d,5)+pow(n_d,5));
              if (s_o_cu == i*100000+j*10000+k*1000+l*100+m*10+n){
                sum += s_o_cu;
                cout << s_o_cu << endl;
              }
            }
          }
        }
      }
    }
  }
  cout << sum << endl;
  return sum;
}