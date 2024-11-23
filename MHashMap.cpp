#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map> 
#include <random>
#include <ctime>
#include <chrono>

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

	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 mt((seed+(int)(rand()*10)));


	//cout << "made hash table" <<endl;
	if(Prime){
		//p=pow(2,31)-1;	
		 p=pow(2,31)-1;
		//p = 1e9+7;
		//cout << "Prime num is " << p << endl;
		
		std::uniform_int_distribution<> uniform_distA(1, p-1);
		std::uniform_int_distribution<> uniform_distB(0, p-1);

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
			if(a[i]<=0){
				cout << "issue with a[i]: "<< a[i] << endl;
			}
			long long ax =(((long long)a[i])*(long long)x);
			if(ax<0){
				cout << "issue with ax:" << ax << " and a[i] is " << a[i] << " and x is " << x << endl;
			}
			if(((ax)%p)+b[i]<0){
				cout << "overflow ax+b" << endl;
			}
			long sum=(((ax)%p)+b[i])%p;
			if(sum<0){
				cout <<"sum " << sum << endl;
			}
			int h=(int)(sum%m);
			
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
			if(a[i]<=0){
				cout << "issue with a[i]: "<< a[i] << endl;
			}
			long long ax =(((long long)a[i])*(long long)x);
			if(ax<0){
				cout << "issue with ax:" << ax << " and a[i] is " << a[i] << " and x is " << x << endl;
			}
			if(((ax)%p)+b[i]<0){
				cout << "overflow ax+b" << endl;
			}
			long sum=(((ax)%p)+b[i])%p;
			if(sum<0){
				cout <<"sum " << sum << endl;
			}
			int h=(int)(sum%m);
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

double MHashMap::load(){
	double fill =0;
	for(int i=0; i<m; i++){
		if(hashTable[i]){
			//cout << "at index i there is a true: " << i << endl;
			fill++;
		}
	}
	return (fill/m);
}

MHashMap::~MHashMap() {
    delete[] hashTable;
}