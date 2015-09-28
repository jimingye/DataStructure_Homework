#include <iostream>
#include <stack>
#include <vector>

using namespace::std;

string inverse(stack<char> s)
{
	string str;
	vector<string> svec;
	s.pop();
	while(!s.empty())
	{
		char c = s.top();
		s.pop();
		if(c != ' ')
			str += c;
		else
		{
			svec.push_back(str);
			str.clear();
			c = '\0';
		}
	}
	svec.push_back(str);
	str.clear();
	for(auto iter = svec.rbegin(); iter != svec.rend(); ++iter)
		str += *iter + " ";
	return str;
}

int main()
{
	stack<char> stk;
	char c; 
	while(cin >> noskipws >> c)
		stk.push(c);
	//while(!stk.empty())
	//	cout << stk.pop();
	//cout << endl;
	cout << inverse(stk);
	return 0;
}