#include <iostream>
#include <stack>
#include <vector>

using namespace::std;

void inverse(char &c)
{
	stack<char> s;
	string str;
	while (cin >> noskipws >> c)
	{
		s.push(c);
		if(c == ' ' || c == '\n')
		{
			s.pop();
			while(!s.empty())
			{
				cout << s.top();
				s.pop();
			}				
			cout << ' ';
		}
	}
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	//return str;
}

int main()
{
	char c; 
	inverse(c);
	cout << endl;
	return 0;
}