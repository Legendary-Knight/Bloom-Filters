#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map> 
#include <random>
#include <ctime>

#include "HashMap.h"
using namespace std;

HashMap::HashMap(bool Prime){
	if(Prime){
		p=pow(2,31)-1;
		hashTable= new bool[p+1];

		mt19937 mt(time(nullptr));
		std::uniform_int_distribution<> uniform_distB(0, p-1);
		std::uniform_int_distribution<> uniform_distA(1, p-1);			

		a=uniform_distA(mt);
		b=uniform_distB(mt);
	}
	else{
		
	}

	hashTable=new bool[m];
	for(int i=0; i<m; i++){
		hashTable[i]=false;
	}
}
void HashMap::primeMap(int x){
	int h=(((a*x)+b)%(p))%(m);
	hashTable[h]=true;
}