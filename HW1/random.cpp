#include <iostream> 
#include <cstdlib> 
  
using namespace::std;  
int main() 
{  
srand(time(NULL));  
for(int i = 0; i < 10;i++ )  
    {
		cout << rand() % 50 + 51<< '\t';
		cout << rand() % 190 + 11 << '\t';
		cout << (rand() % 5 + 1)/10.0 << '\t';
		cout << rand() % 9000000000 + 1000000000 << '\t';
		cout << endl;
	}
return 0; 
}