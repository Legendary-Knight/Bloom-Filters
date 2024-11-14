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
	private:
		int a;
		int b;
		int m;
		int p;
		int* hashTable;
};