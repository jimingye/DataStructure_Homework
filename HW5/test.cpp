#include <iostream>
#include <string>

using namespace::std;

int main()
{
	string s;
	int n;
	getline(cin, s);
	auto siter = s.begin();
	while(1)
	if(siter > s.end())
	{
		cout << *(siter - 2) << endl;
		break;
	}
	else 
		siter = siter + 2;
	//for(; siter <= s.end() - 1; siter = siter + 2)
	//{
	//	cout << *siter << endl;
	//	++n;
	//}
	//cout << *siter << endl;
	return 0;
}