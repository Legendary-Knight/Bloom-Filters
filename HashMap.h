#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map> 

class HashMap {
	public:
		HashMap(bool Prime);
		void primeMap(int val);
		int getM(){return m;}
	private:
		// N will be (2^31)-2
		int N=(pow(2,31))-2;
		//n is 100,000
		int n=100000;
		// c and k are 10,000
		int c=10;
		int k=10;

		int a;
		int b;
		int m=c*n;
		int p;
		bool* hashTable;
};