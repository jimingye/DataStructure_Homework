#include <iostream>
#include <cstdio>
using namespace::std;
void hanoi (int n, char from, char buffer, char to)
{
    if (n == 1)
    {
        cout << " Move disk " << n << " from " << from << " to " << to << endl;
    }
    else
    {
        hanoi (n-1, from, to, buffer);
        cout << " Move disk " << n << " from " << from << " to " << to << endl;
        hanoi (n-1, buffer, from, to);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi (n, 'A', 'B', 'C');
    return 0;
}
