#include <iostream>
#include <string>
#include <unordered_set>

using namespace::std;

unordered_set<string> suset;

void Parantheses_pair(int n, string a, string b, string c)
{
	if (n == 1)
	{
		string str;
		str = a + "(" + b + ")" + c;
		suset.insert(str);
	}
	else
	{
		string d = "";
		string base1 = a + "(" + ")";
		Parantheses_pair(n - 1, base1, b, c);
		string base2 = "(" + b + ")";
		Parantheses_pair(n - 1, a, base2, c);
		string base3 = d + "(" + ")" + c;
		Parantheses_pair(n - 1, a, b, base3);
	}
}

int main()
{
	Parantheses_pair(3, "", "", "");
	for(auto c : suset)
		cout << c << endl;
	return 0;
}