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
		void mapVal(int val);

	private:
		// N will be (2^31)-2
		int N;
		//n is 100,000
		int n;
		// c and k are 10,000
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