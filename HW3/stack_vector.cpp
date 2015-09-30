#include <iostream>
#include <stack>
#include <vector>

using namespace::std;

string inverse(char &c)
{
	stack<char> s;
	string str;
	while (cin >> noskipws >> c)
		{
			s.push(c);
			if(c == ' ')
			{
				s.pop();
				while(!s.empty())
				{
					str += s.top();
					s.pop();
				}
				str += ' ';
			}
		}
		s.pop();
		while(!s.empty())
		{
			str += s.top();
			s.pop();
		}
	return str;
}

int main()
{
	char c; 
	cout << inverse(c);
	cout << endl;
	return 0;
}