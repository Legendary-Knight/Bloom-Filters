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
	cout << "starting main" <<endl;
	// N will be (2^31)-2
	int N=(pow(2,31))-2;
	//n is 100,000
	int n=100000;
	// c and k are 10,000
	int c=10;
	int k=10;
	bool prime =true;
	cout << "running hash" <<endl;
	MHashMap myHash(prime, N, n, c, k);
	myHash.mapVal(10000);
	return 0;
}