#include <iostream>
#include <cstdlib>

using namespace::std;

int main()
{
	srand(time(NULL));
	for(int i = 0; i < 5; ++i)
		{
			int m = rand();
			cout << m << endl;
		}
		return 0;
}
