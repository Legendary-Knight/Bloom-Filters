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
	p=pow(2,31)-1;
	hashTable= new int[p+1];

	mt19937 mt(time(nullptr));
	std::uniform_int_distribution<> uniform_distB(0, p-1);
	std::uniform_int_distribution<> uniform_distA(1, p-1);			

	a=uniform_distA(mt);
	b=uniform_distB(mt);

}
void HashMao::primeMap(int x){
	int h=(((a*x)+b)%(p))%(m);
}