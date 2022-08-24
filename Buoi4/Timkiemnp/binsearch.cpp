
#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

int binarySearch(int arr[], int n, int x)
{
    int r = n - 1;
    int l = 0;
    while (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return r = mid - 1;
        if (arr[mid] < x)
            return l = mid + 1;
    }

    return -1;
}

int bin2search(int arr[], int x, int l, int r)
{
    int mid;
    if (l > r)
    {
        return 0;
    }
    else
    {
        mid = l + (r - l) / 2;

        if (x == arr[mid])
            return mid;
        else
        {
            if (x > arr[mid])
                return bin2search(arr, x, mid + 1, r);
            else
                return bin2search(arr, x, l, mid - 1);
        }
    }
}

int main()
{
    int arr[] = {1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = sizeof(arr) / sizeof(int);
    int x = 7;

    int vitri = binarySearch(arr, n, x);

    int vitri2 = bin2search(arr,x,0,n-1);

    cout << vitri << " " << vitri2;
}