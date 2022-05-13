#include<bits/stdc++.h>
#include<iostream>
#include<windows.h>

using namespace std;

#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<ll,ll>
#define mii map<int,int>
#define mod 1e9+7
#define fl(i,n) for(int i = 0;i < n;i++)
#define nl '\n'


void setIO()
{
    faster
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
}

void merge(int arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);

    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


int main()
{

    setIO();

    srand(time(0));
    DWORD st = GetTickCount();
    for(int x=0; x<1000; x++)
    {
        int arr[10000+2];
        for(int i=0; i<10000; i++)
            arr[i] = rand();

        int size = sizeof(arr)/sizeof(arr[0]);
        mergeSort(arr, 0, size - 1);

    }
    DWORD ed = GetTickCount();
    DWORD r = ed-st;
    cout<<"total time taken for merge sort = "<<r<<" ms\n";


    st = GetTickCount();
    for(int x=0; x<1000; x++)
    {
        int arr[10000+2];
        for(int i=0; i<10000; i++)
            arr[i] = rand();

        int n = sizeof(arr) / sizeof(arr[0]);
        quickSort(arr, 0, n - 1);
    }
    ed =  GetTickCount();
    DWORD r2 = ed-st;
    cout<<"total time taken for quick sort = "<<r2<<" ms\n";
    if(r>r2)
        cout<<"Difference in time = "<<r-r2<<" ms\n";
    else
        cout<<"Difference in time = "<<r2-r<<" ms\n";


    return 0;

}
