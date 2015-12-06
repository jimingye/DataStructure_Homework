#include <iostream>
#include <sstream>
#include <queue>

using namespace::std;

int stringToNum(string str)
{
	istringstream iss(str);
	int num;
	iss >> num;
	return num;
}

int main()
{
	queue<string> sque;
	string str1, str2;
	int array[100];
	int m = -1;
	cout << "please enter the number and sorting mode:" << endl;
	getline(cin, str1);
	istringstream iss(str1);
	while(iss >> str1)
	{
		sque.push(str1);
		++m;
	}
	str2 = sque.front();
	sque.pop();
	for (int n = 0; n != m; ++n)
	{
		array[n] = stringToNum(sque.front());
		sque.pop();
	}
	cout << str2 << endl;
	for(int i = 0; i != m; ++i)
		cout << array[i] << " ";
	return 0;
}