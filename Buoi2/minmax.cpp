#include <iostream>

using namespace std;

int sumOfArray(int a[1000], int n)
{
    if (n == 1)
        return a[0];
    return a[n - 1] + sumOfArray(a, n - 1);
}

int min;

int MaxOfArray(int n, int arr[])
{
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        int a = MaxOfArray(n - 1, arr);
        if (arr[n - 1] > a)
        {
            return arr[n - 1];
        }
        else
            return a;
    }
}
int MinOfArray(int n, int arr[])
{
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        int a = MinOfArray(n - 1, arr);
        if (arr[n - 1] < a)
        {
            return arr[n - 1];
        }
        else
            return a;
    }
}

int main()
{
    int n;
    int arr[1000];
    cout << "Nhap n : ";
    cin >> n;
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // min = a[n];
    //  cout << sumOfArray(arr, n);
    cout << "Min = " << MinOfArray(n,arr) << endl;
    cout << "Max = " << MaxOfArray(n,arr);
    return 0;
}
