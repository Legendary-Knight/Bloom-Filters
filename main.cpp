#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map> 

#include "MHashMap.h"
using namespace std;



int main(){
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
	return 0;
}