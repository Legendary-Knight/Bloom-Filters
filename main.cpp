#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map> 
#include <cmath>
#include <random>

#include "MHashMap.h"
using namespace std;



int main(){

	/*
	FOR TESTING
	//cout << "starting main" <<endl;
	// N will be (2^31)-2
	int N=(pow(2,31))-2;
	//n is 100,000
	int n=100000;
	// c  will range from 5-10
	//k will range from 3-7
	int c=5;
	int k=3;
	bool prime =false;
	//cout << "running hash" <<endl;
	MHashMap myHash(prime, N, n, c, k);
	for(int i=0; i<10000; i++){
		myHash.mapVal(i);
	}
	if(myHash.contains(12345)){
		cout << "Hash does contains 12345"  << endl;
	}
	else{
		cout << "Hash doesn't contains 12345"  << endl;
	}
	*/

	// N will be (2^31)-2
	int N=(pow(2,31))-2;
	//n is 100,000
	int n=500000;
	// c  will range from 5-10
	//k will range from 3-7
	int c=5;
	int k=3;
	bool prime =false;

	MHashMap myHash(prime, N, n, c, k);
	for(int i=0; i<n; i++){
		myHash.mapVal(i);
	}
	for(int )
	mt19937 mt(time(nullptr));
	std::uniform_int_distribution<> uniform_dist(n, N-1);
	double fp=0;
	double inserts=10000;
	for(int i=0; i<inserts; i++){
		if (myHash.contains(uniform_dist(mt))){
			cout << "a false positive" << endl;
			fp++;
		}
	}
	double fpr=fp/inserts;
	cout << "False positive rate is: " << fpr << " or " << fpr*100 << "%" << endl;


	return 0;
}