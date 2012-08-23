//is_abundant.c

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LIMIT 28123
#define NUM_AB 6965


int is_factor(int n, int factor);
int sum_of_factors(int n);
int is_abundant_command_line_arg(int argc, char *argv[]);
int is_abundant(int n);
int ab_list(int len, int abnumlist[len], int limit);
void pair_sum_list(int len, int *numlist, int *pairarrayout);
int in_list(int len, int *sumlist, int element);

static ablist[NUM_AB];
static pairlist[NUM_AB*NUM_AB];


int main() {
	//populate numlist:	
	ab_list(NUM_AB, ablist, LIMIT);
	printf("%d\n",ablist[0]);
	
	//populate pairlist:
	pair_sum_list(NUM_AB, ablist, pairlist);
	
	//sum all integers < LIMIT unless they are an element of pairlist:
	int sum,i;
	sum = 0;
	for (i=0; i<(LIMIT); ++i) {
		if (in_list(NUM_AB*NUM_AB, pairlist, i)){
			;
		}
		else {
			sum += i;
		}
	}
	printf("%d", sum);
	return sum;
	
}

//this function takes a static array, numlist[len], and populates
//another static array, pairarrayout[len*len], with all 
//possible ordered pairs of numlist[len]
void pair_sum_list(int len, int *numlist, int *pairsum) {
	numlist = &numlist[0];
	pairsum = &pairsum[0];
	int i,j,a;
	a=0;
	for (i=0; i<len; ++i){
		for (j=0; j<len; ++j){
			pairsum[a] = numlist[i]+numlist[j];
			++a;
		}
		
	}
	printf("%d\n", pairsum[0]);
}

//takes an array sumlist[len], (in this case a list of pairsums)
//and sums together all of the elements.
int in_list(int len, int *sumlist, int element) {
	int i;
	for (i=0; i<len; ++i) {
		if (element == sumlist[i])
			return 1;
	}
	return 0;
}



//NEED TO FIGURE OUT HOW TO PASS AN ARRAY TO A FUNCTION!
//this function takes a static array, abnumlist[len], 
//and fills the list with abundant numbers
int ab_list(int len, int *abnumlist, int limit) {
	abnumlist = &abnumlist[0];
	int i,a;
//initialize array abnumlist
	for (i=0; i<len; ++i) {
		abnumlist[i] = 0;
	}
//populate abnumlist; the ith element in abnum is the value of the ith abundant number
	a=0;
	for (i=1; i<=limit; ++i) {
		if (is_abundant(i)) {
			abnumlist[a] = i;
			++a;
		}
	}
	return 0;
}

int is_abundant(int n) {
	if ((sum_of_factors(n) > n)) {
		return 1;
	}
	return 0;
}


int is_abundant_command_line_arg(int argc, char *argv[]) {
	if (argc > 2 || argc == 0) {
		printf("Whoa there buddy\n");
	}
	else {
		long a = atoi(argv[1]);
		int i;
		for (i=1; i<=a; ++i) {
			if ((sum_of_factors(i)) > i) {
				printf("%d is abundant\n", i);
			}
		}
	}
	return 0;
}


int is_factor(int n, int factor) {
	if (n % factor == 0) {
		return 1;
	}
	return 0;
}


int sum_of_factors(int n) {
	int factors[(n/2)], i, sum;
	for (i=1; i<=(n/2); ++i) {
		factors[i]=0;
	}
	for (i=1; i<=(n/2); ++i){
		if (is_factor(n, i)){
			factors[i] = 1;
		}
	}
	sum=0;
	for (i=1; i<=(n/2); ++i){
		if (factors[i])
			sum+=i;
	}
	return sum;
}






