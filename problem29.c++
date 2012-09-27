//problem29.c++

#include <cmath>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <map>
#include <cassert>


using namespace std;

vector<bool> sieve_of_eratosthenes(int p_len);
vector<int> trial_division(int c);
vector<int> exp_prime_decomp(int base, int exp, map< int, vector<int> > p_dec_map);
map< int, vector<int> > p_fact_map(int n);

//every exponentiation of a prime base is unique.

//initialize primelist
vector<bool> static const p_list = sieve_of_eratosthenes(1000);


int main() { 

  //initialize map< int, prime_decomposition > (key = int, value = its prime decomp)
  map< int,vector<int> > p_fact = p_fact_map(100);
  
  
  // vector<int> p1 = exp_prime_decomp(2, 4, p_fact);
  // sort(p1.begin(), p1.end());
  // vector<int> p2 = exp_prime_decomp(4,2, p_fact);
  // sort(p2.begin(), p2.end());
  // cout << (p1 == p2) << endl;
  // for (int i=0; i<p1.size(); i++){
  //   cout << p1[i] << endl;
  // }
  
  //initialize vector of vectors, where each element is the prime decomposition of an integer
  vector< vector<int> > p_decomp;
  
  for (int i=2; i<=100; i++) {
    for (int j=2; j<=100; j++){
      vector<int> p_decomp_vect = exp_prime_decomp(i, j, p_fact);
      sort(p_decomp_vect.begin(), p_decomp_vect.end());
      bool include = find(p_decomp.begin(), p_decomp.end(), p_decomp_vect) != p_decomp.end();
      if (!include) {
        p_decomp.push_back(p_decomp_vect);
      }
    }
  }

  int size = p_decomp.size();
  cout << size << endl;
  
  return 0;
}


//finds the prime decomposition of a base <= 100 taken to any power
vector<int> exp_prime_decomp(int base, int to_exp, map< int, vector<int> > p_dec_map) {
  vector<int> exp_p_list;
  vector<int> p_list = p_dec_map[base];
  for (int i=0; i<to_exp; i++){
    exp_p_list.insert(exp_p_list.end(), p_list.begin(), p_list.end());
  }
  return exp_p_list;
}

//creates a map of (n-2) keys, each of whose values
//is a vector containing the prime decomposition of the respective key i, where 2<=i<=n.
map< int, vector<int> > p_fact_map(int n) {
  map< int, vector<int> > p_fact;
  for (int i=2; i<=n; i++) {
    vector<int> test = trial_division(i);
    p_fact[i] = test;
  }
  return p_fact;
}


vector<int> trial_division(int c){
  assert(c>1);
  
  vector<int> prime_factors;
  
  if (p_list[c]) {
    prime_factors.push_back(c);
    return prime_factors;
  }

  for (int i=(c-1); i>1; i--){
    if (c%i==0) {
      if (p_list[i]){
        vector<int> branch1 = trial_division(c/i);
        prime_factors.push_back(i);
        prime_factors.insert(prime_factors.end(), branch1.begin(), branch1.end());
        return prime_factors;
      }
      vector<int> branch1 = trial_division(i);
      vector<int> branch2 = trial_division(c/i);
      prime_factors.insert(prime_factors.end(), branch1.begin(), branch1.end());
      prime_factors.insert(prime_factors.end(), branch2.begin(), branch2.end());
      return prime_factors;
    }
  }
}



vector<bool> sieve_of_eratosthenes(int p_len){
//initialize list to true
  vector<bool> plist; 
  for (int i=0; i<p_len; i++) {
    plist.push_back(true);
  }
  
//deal with the special cases  
  plist[0] = false;
  plist[1] = false;
  
//the sieve
  for (int i=2; i<ceil(sqrt(p_len)); i++){
    if (plist[i]) {
      int k;
      for (int j=pow(i,2.0), k=1; j<=p_len; j = pow(i,2.0) + k*i, k++){
        plist[j]=false;
      }
    }
  }
  
  return plist;
}







