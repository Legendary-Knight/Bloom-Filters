#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map> 
#include <random>
#include <ctime>

#include "MHashMap.h"
using namespace std;

MHashMap::MHashMap(bool Prime, int NI, int nI, int cI, int kI){
	prime=Prime;
	N=NI;
	n=nI;
	c=cI;
	k=kI;
	m=c*n;

	
	hashTable=new bool[m];
	for(int i=0; i<m; i++){
		hashTable[i]=false;
	}
	mt19937 mt(time(nullptr)+(rand()*100000));
	//cout << "made hash table" <<endl;
	if(Prime){
		p=pow(2,31)-1;
		//cout << "Prime num is " << p << endl;
		std::uniform_int_distribution<> uniform_distB(0, p-1);
		std::uniform_int_distribution<> uniform_distA(1, p-1);			
		for(int i=0; i<k; i++){
			a.push_back(uniform_distA(mt));
			b.push_back(uniform_distB(mt));
			//cout << "a of " << i << " is " << a[i] << endl;
			//cout << "b of " << i << " is " << b[i] << endl;
		}
	}
	else{
		//cout << "in non prime hash" << endl;
		for(int i=0; i<k; i++){
			int newSeed=mt();
			//cout << "new seed " << newSeed << endl;
			SEED.push_back(newSeed);
		}
	}
}

void MHashMap::mapVal(int x){
	if(prime){
		for(int i=0; i<k; i++){
			long sum=(((long)(a[i])*x)+b[i]);
			//cout <<"sum " << sum << endl;
			int h=((int)(sum%(p)))%(m);
			hashTable[h]=true;
		}
	}
	else{
		for(int i=0; i<k; i++){
			unsigned int combSeed=(SEED[i]+x);
			//cout << "combined seed " << combSeed << endl;
			std::mt19937 gen(combSeed);
			std::uniform_int_distribution<> uniform_distM(0, m-1);
			int h=uniform_distM(gen);
			hashTable[h]=true;
		}
	}
}

bool MHashMap::contains(int x){
	bool contain = true;
	if(prime){
		for(int i=0; i<k; i++){
			long sum=(((long)(a[i])*x)+b[i]);
			//cout <<"sum " << sum << endl;
			int h=((int)(sum%(p)))%(m);
			if(hashTable[h]==false){
				contain=false;
			}
		}
	}
	else{
		for(int i=0; i<k; i++){
			unsigned int combSeed=(SEED[i]+x);
			//cout << "combined seed " << combSeed << endl;
			std::mt19937 gen(combSeed);
			std::uniform_int_distribution<> uniform_distM(0, m-1);
			int h=uniform_distM(gen);
			if(hashTable[h]==false){
				contain=false;
			}
		}
	}
	return contain;
}

