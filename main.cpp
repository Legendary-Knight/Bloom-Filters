#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map> 
#include <cmath>
#include <random>
#include <algorithm>
#include <chrono>

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

	int N=(pow(10,7));
	//n is 50,000
	int n=50000;
	bool prime=true;
	//test
	// c  will range from 5-10
	//k will range from 3-7
	//int c=5;
	//int k=3;

	//run twice and change from true to false
/*
	MHashMap myHashT(true, N, n, 5, 3);
	int y=n-1;
	
	for(int i=0; i<n; i++){
					myHashT.mapVal(y);
			}
	for(int i=0; i<2*n; i++){
		if (myHashT.contains(i)){
			cout << "contains " << i << endl;
		}
		else {
			cout << "doesn't contain " << i << endl;
		}		
	}
	*/



	for(int c=5; c<=10; c++){
		for(int k=3; k<=8; k++){
			vector<double> fps;
			for(int it=0; it<10; it++){
				MHashMap myHash(prime, N, n, c, k);
				for(int i=0; i<n; i++){
					myHash.mapVal(i);
				}
				//cout << "Fill/spread is "  << myHash.load() << endl;
				unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
				mt19937 mt((seed+(int)(rand()*10))+it);
				std::uniform_int_distribution<> uniform_dist(n+1, N-2);
				double fp=0;

				double inserts=10000;
				for(int i=0; i<inserts; i++){
					if (myHash.contains((int)(uniform_dist(mt)))){
						//cout << "a false positive" << endl;
						fp++;
					}
				}
				double fpr=((double)(fp))/inserts;
				fps.push_back(fpr);
				cout << "False positive rate is: " << fpr << " or " << fpr*100 << "%" << endl;
			}
			sort(fps.begin(), fps.end());
			double medFp = (fps[4]+fps[5])/2;
			cout<< "MEDIAN false positive rate is: " << medFp << " or " << medFp*100 << "%" << " for c value of: " << c << " and k of: " << k << endl;
		}
	}

	
	return 0;
}