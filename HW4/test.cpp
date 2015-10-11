#include <iostream>
#include <unordered_set>

using namespace::std;

int main()
{
	unordered_set<int> iuset;
	int n;
	while(cin >> n)
		iuset.insert(n);
	for(auto m : iuset)
		cout << m;
	return 0;
}