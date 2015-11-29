#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>        
#include <cstdlib>      

int myrandom (int i) { return rand()%i;}
using namespace::std;

int main()
{
	srand ( unsigned ( time(0) ) );
	int capacity = 1024;
	vector<int> ivec;
	for(int n = 0; n != capacity; ++n)
		ivec.push_back(n);
	random_shuffle(ivec.begin(), ivec.end(), myrandom);
	for(auto m : ivec)
		cout << m << ' ';
	return 0;
}