#include<bits/stdc++.h>
#include<iostream>

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

void insertion(int arr[],int &n)
{
    int x;
    cin>>x;
    arr[n]=x;
    int j = n;
    for(int i = n/2 -1;i>=0;i--)
    {
        
        if(arr[j]>arr[i])
        {
            cout<<"comparing with "<<arr[i]<<'\n';
            swap(arr[j],arr[i]);
            j=i;
        }
        else
            break;
    }
    n++;
}

void heapify(int arr[],int i,int n)
{
    int prevParent,left,right;
    prevParent = i;
    left = 2*i+1;
    right = 2*i+2;

    if(left<n && arr[left]>arr[prevParent])
        prevParent = left;
    
    if(right<n && arr[right]>arr[prevParent])
        prevParent = right;
    
    if(prevParent != i)
    {
        swap(arr[i],arr[prevParent]);
        heapify(arr,prevParent,n);
    }

    return ;
}

void heapSort(int arr[],int n)
{
    for(int i=n/2 -1 ;i>=0;i--)
        heapify(arr,i,n);

    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
    return ;
}

void printHeap(int arr[],int n)
{
    cout<<"Sorted array : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" \n"[i==n-1];
}

int main()
{
    setIO();
    srand(time(0));
    int n;
    cin>>n;
    int arr[n+100];
    for(int i=0;i<n;i++)
        arr[i]=rand()%100;
    heapSort(arr,n);
    printHeap(arr,n);
    cout<<"how many elements do you want to insert?\n";
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
        insertion(arr,n);
    heapSort(arr,n);
    printHeap(arr,n);
    return 0;
}