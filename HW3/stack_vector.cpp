#include <iostream>
#include <stack>
#include <vector>

using namespace::std;

int main()
{
	char c;
	vector<char> cvec;
	stack<char> cstk;
	while(cin >> noskipws >> c)
	{
		if(c != ' ')
			cstk.push(c);
		else
		{
			while(!cstk.empty())
			{
				cvec.push_back(cstk.top());
				cstk.pop();
			}
			cvec.push_back(' ');
		}
	}
	cstk.pop();
	while(!cstk.empty())
	{
		cvec.push_back(cstk.top());
		cstk.pop();
	}
	for(auto c1 : cvec)
		cout << c1;
	cout << endl;
	return 0;
}