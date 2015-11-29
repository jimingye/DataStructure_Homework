#include <iostream>
#include <algorithm>
using namespace::std;

int main()
{
	int array[10];
	int m = 0;
	for(int n = 0; n != 10; ++n)
	{
		int i;
		char c;
		if(cin >> i)
		{
			array[n] = i;
			++m;
		}
		else if(cin >> c)
			break;
	}
	cout << m << array[0] << ' ' << array[1] << ' ' << array[2] << endl;
	return 0;
}