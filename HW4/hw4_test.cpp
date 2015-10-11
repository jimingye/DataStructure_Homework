#include <iostream>
#include <string>
#include <unordered_set>

//this method is not valid, it just based on the n-1 pairs of () to generate the n's (). So there are may be some probabilitis we cannot find some valid pairs in n. Such as (())(()) in 4, we cannot generate this pair from 3. Because ())(() in 3 is invalid. So the catalan method is a better method. 
//But maybe this method is good for other recursion problems~

using namespace::std;

void makepair(unordered_set<string> &suset, string a, string b, string c, int n)
{
	string str = a + "(" + b + ")" + c;
	if(n == 1)
	{
		suset.insert(str);
		return;                           
	}

	if(n > 0)
	{
		makepair(suset, str, "", "", n - 1);
		makepair(suset, "", str, "", n - 1);
		makepair(suset, "", "", str, n - 1);
	}
}

unordered_set<string> P_pair(int n)
{
	unordered_set<string> pair;
	makepair(pair, "", "", "", n);
	return pair;
}

int main()
{
	cout << "please enter the numbers of paretheses pairs: " << endl;
	int n;
	cin >> n;
	unordered_set<string> suset = P_pair(n);
	for (auto c : suset)
		cout << c << endl;
	return 0;
}