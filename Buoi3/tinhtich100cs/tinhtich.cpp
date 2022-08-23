// Tinh a x b voi a ko qua 100 chu so va b = (1,9)

#include <iostream>

using namespace std;

void reverse(int arr[], int start, int end)
{

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] ;

    cout << endl;
}


void tinhaxb(int a[], int n, int b)
{   
    reverse(a, 0, n-1);
    int c[100];
    int nho =0;
    int j = 0;
    for(int i = 0; i < n; i++){
        int tg  = a[i] * b + nho;
        c[j++] = tg % 10;
        nho = tg/10;
    }
    if(nho > 0){
        c[j++] = nho;
    }
    reverse(c,0,j-1);
    printArray(c,j);
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 6, 5, 3, 5, 7};
    int n = sizeof(arr)/sizeof(int);

    tinhaxb(arr,n,9);

}