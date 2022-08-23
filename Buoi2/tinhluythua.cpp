#include <iostream>

using namespace std;

int luythua(int x, int n)
{
    if (n == 1) return x;

    else return luythua(x,n-1)*x;
}

int main()
{
    
    cout << luythua(2,10);
}