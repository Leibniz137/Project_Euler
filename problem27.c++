//problem27.c++

#include <iostream>
#include <cmath>

bool* sieve_of_eratosthenes(bool *n, int n_len);
int prime_quad_coef_prod(bool *sieved_bool, int sieved_bool_len);
int prime_series(bool *sieved_bool, int sieved_bool_len, int lin_coef, int con_coef);
bool gives_prime(bool *sieved_bool, int sieved_bool_len, int lin_coef, int con_coef, int n);

int main() {
//initialize bool list
  bool a[1000000];
  for (int i=0; i<1000000; i++) {
    a[i] = true;
  }
  
//sieve it
  sieve_of_eratosthenes(a, 1000000);
  
  std::cout << prime_quad_coef_prod(a, 100000) << std::endl;
  
  return 0;
}

//given a pointer to an array of boolean's, n, initialized to true and of len(n)
//returns the array with True at prime indices 
bool* sieve_of_eratosthenes(bool *n, int n_len) {
  n[0] = false;
  n[1] = false;
  for (int i=2; i<ceil(sqrt(n_len)); i++){
    if (n[i]) {
      int k;
      for (int j=pow(i,2), k=1; j<=n_len; j = pow(i,2) + k*i, k++){
        n[j]=false;
      }
    }
  }
  return n;
}

//takes a bool array, where prime indices are true and composite indices are false
//returns the product of the coefficients that produce the most consecutive primes
int prime_quad_coef_prod(bool *sieved_bool, int sieved_bool_len) {
  int a_b[] = {0,0};
  int max_len_prime_series, len_prime_series;
  max_len_prime_series = len_prime_series = 0;
  for (int a=-1000; a<=1000; a++) {
    for (int b=-1000; b<=1000; b++) {
      len_prime_series = prime_series(sieved_bool, sieved_bool_len, a, b);
      if (len_prime_series > max_len_prime_series) {
        max_len_prime_series = len_prime_series;
        a_b[0] = a;
        a_b[1] = b;
      }
    }
  }
  return a_b[0]*a_b[1];
}



int prime_series(bool *sieved_bool, int sieved_bool_len, int lin_coef, int con_coef) {
  int i=0;
  while (gives_prime(sieved_bool, sieved_bool_len, lin_coef, con_coef, i)) {
    ++i;
  }
  return i-1;
}



bool gives_prime(bool *sieved_bool, int sieved_bool_len, int lin_coef, int con_coef, int n) {
  int poly;
  poly = pow(n, 2) + lin_coef*n + con_coef;
  if (sieved_bool[poly]){
    return true;
  }
  return false;
}








