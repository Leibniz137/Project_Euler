//problem31.c++

//change-making problem
//(problem31.sce uses a valid, but inefficient generating function)

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;


const static int I = 1;
const static int II = 2;
const static int V = 5;
const static int X = 10;
const static int XX = 20;
const static int L = 50;
const static int C = 100;
const static int CC = 200;



int main() {
  int count = 0;
  for (int i=0; i<=(200/I); i++){
    for (int j=0; j<=(200/II); j++){
      for (int k=0; k<=(200/V); k++){
        for (int l=0; l<=(200/X); l++){
          for (int m=0; m<=(200/XX); m++){
            for (int n=0; n<=(200/L); n++){
              for (int o=0; o<=(200/C); o++){
                bool diophantine = (I*i) + (II*j) + (V*k) + (X*l) + (XX*m) + (L*n) + (C*o) == 200;
                if (diophantine) {
                  count++;
                }
              }
            }
          }
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}


















