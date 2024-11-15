#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map> 
using namespace std;

class MHashMap {
	public:
		//MHashMap(){};
		MHashMap(bool Prime, int NI, int nI, int cI, int kI);
		void mapVal(int x);
		bool contains(int x);

	private:
		// N will be (2^31)-2
		int N;
		//n is 500,000
		int n;
		// c  will range from 5-10
		//k will range from 3-7
		int c;
		int k;

		vector<int> a;
		vector<int> b;
		int m;
		int p;
		bool prime;
		bool* hashTable;
		vector<int> SEED;
};