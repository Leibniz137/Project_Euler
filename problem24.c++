//problem24.c++

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>

long int ith_lex_perm(int *n, int n_len, long int i);
void populate_list_minus_an_element_by_index(int i, int *oldlist, int n_len, int *newlist);
long int fact(int n);
int* range(int a[], int n);
void print_list(int *n, int n_len);
bool in_lex_order(int *a, int a_arraysize, int *b, int b_arraysize);


int main() {
  int o[] ={1,2,3,4};
  int n[] = {0,1,2,3,4,5,6,7,8,9};
  int m[9];

  long int answer;
  answer = ith_lex_perm(n, 10, 1000000);
  std::cout << answer << std::endl;
  return 0;
}


//what's the ith lexical permutation of n unique digits?
long int ith_lex_perm(int *n, int n_len, long int i) {
  if (n_len <= 1) {
    long int first_digit;
    first_digit = n[0];
    return first_digit;
  }

  
  long int nth_lp; //the number of lexical permutations (equivalently, the last lexical permuation)
  nth_lp = fact(n_len);
  
//permutations form a finite symmetry group, so some numbers i will be greater than |S|
  if (i>nth_lp) {
    printf("there is no %ldth lexical permutation of %d consecutive ints\n", i, n_len);
    throw(1);
  }
  
  
  long int j, last_digit;
  int k, q;
  int newlist[n_len-1];
  for (j=k=0; j <= nth_lp; j += fact(n_len-1), k++) { 
    if (i<=j) {
      last_digit = (n[k-1])*(pow(10,(n_len-1)));
      std::cout << "index: " << k-1 << "  element: " << n[k-1] << std::endl;
      populate_list_minus_an_element_by_index((k-1), n, n_len, newlist);
      print_list(newlist, n_len-1);
      if (i%fact(n_len-1)==0) {
        q = fact(n_len-1);
      } 
      else {
        q = i%fact(n_len-1);
      }
      return last_digit+ith_lex_perm(newlist, n_len-1, q);
    }
  }
}



void populate_list_minus_an_element_by_index(int i, int *oldlist, int n_len, int *newlist) {
  //it is presumed that len(newlist) == n_len-1
  int l, m;
  for (l=m=0; l<(n_len); l++, m++) {
    if (l == i) {
      l++;
    }
    newlist[m] = oldlist[l];
  }
}

long int fact(int n) {
  long int prod=1;
  for (int i=1; i<=n; i++) {
    prod *= i;
  }
  return prod;
}



//fills an empty array, a, where len(a) == n, with consecutive int's starting @ 0
int* range(int a[], int n) {
  for (int i=0; i<n; i++) {
    a[i] = i;
  }
  return a;
}

void print_list(int *n, int n_len) {
  for (int i=0; i<n_len; i++) {
    std::cout << n[i] << std::endl;
  }
}

bool in_lex_order(int *a, int a_arraysize, int *b, int b_arraysize) {
  //determine which array is smaller
  int arraysize;
  arraysize = std::min(a_arraysize, b_arraysize);
  
  //test for lexicographic order
  for (int i=0; i<arraysize; i++) {
    if (a[i] < b[i]) {
      return true;
    }
    else if (a[i]==b[i]) {
      if (i==(arraysize-1)) {
        if (a_arraysize < b_arraysize) {
          return true;
        }
        return false;
      }
      else {
        continue;
      }
    }
    else {
      break;
    }
  }
  return false;
}