//problem32.c++

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;



string convertInt(int number);
int stringSum(string s);
bool is_ninepandigital(int a, int b);
//find all [1,9] pandigital multiplier * multiplicand = product
// a * b = c, where len(a)+len(b) == len(c) can occur only when len(a)==1 and len(b)==3 or 4
//or when len(a)==2 and len(b)==2 or 3


int main() {
  string const non_zero_digits = "123456789";
  vector<int> products;


  for (int i=1; i<1000; i++){
    for (int j=1; j<10000; j++){
      if (is_ninepandigital(i,j)){
        products.push_back(i*j);
      }
    }
  }
  // //where len(a) == 1 and len (b) == 3
  //   for (int i=1; i<10; i++){
  //     for (int j=100; j<1000; j++){
  //       if (is_ninepandigital(i,j)){
  //         products.push_back(i*j);
  //       }
  //     }
  //   }
  //   
  //   //where len(a) == 1 and len(b) == 4
  //   for (int i=1; i<10; i++){
  //     for (int j=1000; j<10000; j++){
  //       if (is_ninepandigital(i,j)){
  //         products.push_back(i*j);
  //       }
  //     }
  //   }
  //   
  //   //len(a) == len(b) == 2
  //   for (int i=10; i<100; i++){
  //     for (int j=10; j<100; j++){
  //       if (is_ninepandigital(i,j)){
  //         products.push_back(i*j);
  //       }
  //     }
  //   }
  //   
  //   //where len(a) == 2 and len(b) == 3
  //   for (int i=10; i<100; i++){
  //     for (int j=100; j<1000; j++){
  //       if (is_ninepandigital(i,j)){
  //         products.push_back(i*j);
  //       }
  //     }
  //   }
  
  vector<int>::iterator it;
  
  it  = unique(products.begin(), products.end());
  
  products.resize( it - products.begin() );
  
  int prod_sum = 0;
  for (int i=0; i<products.size(); i++){
    prod_sum += products[i];
  }
  
  cout << prod_sum << endl;
  
  
  return 0;
}


// void unique_bang(vector<int> prod_vect){
//   for (int i=0; i<prod_vect.size(); i++){
//     find(prod_vect.begin(), prod_vect.end()prod_vect[i]
//   }
// }


bool is_ninepandigital(int a, int b){
  int prod = a*b;
  string digits = convertInt(a) + convertInt(b) + convertInt(prod);
  sort(digits.begin(), digits.end());
  if (digits == "123456789"){
    return true;
  }
  return false;
}


int stringSum(string s){
  int sum = 0;
  for (int i=0; i<s.size(); i++){
    sum += s[i];
  }
  return sum;
}



string convertInt(int number){
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

