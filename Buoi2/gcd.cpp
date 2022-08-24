
#include <iostream>

using namespace std;

int ucln(int a, int b)
{
    if (b == 0)
        return a;
    if (a % b == 0)
        return b;
    return ucln(b, a % b);
}

int main()
{
    int a = 4, b = 2;
    cout << ucln(a, b);
}