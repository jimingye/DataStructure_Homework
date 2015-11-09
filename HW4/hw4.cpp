/*
Homework_4
Jiming Ye
N16566270
jy1769@nyu.edu
Mac OSX
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void makepair(vector<string> &svec, string str, int left, int right)
{
	if(left == 0 && right == 0)
	{
		svec.push_back(str);
		return;
	}

	if(left > 0)                                                         //left should always be less or equal to right.
		makepair(svec, str + "(", left - 1, right);
	if (left < right)
		makepair(svec, str + ")", left, right - 1);
}

vector<string> P_pair(int n)                                             //call the recursion function.
{
	vector<string> pair;
	makepair(pair, "", n, n);
	return pair;
}

int main()
{
	cout << "please enter the number of paretheses pairs: " << endl;
	int n;
	cin >> n;
	vector<string> svec = P_pair(n);
	for (auto c : svec)
		cout << c << endl;
	return 0;
}