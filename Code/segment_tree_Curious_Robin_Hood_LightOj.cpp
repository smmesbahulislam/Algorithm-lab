#include<bits/stdc++.h>
using namespace std;

#define mx 100005

int arr[mx];
int tree[mx * 4];

void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b+e)/2;
    
    init(left,b,mid);
    init(right,mid+1,e);

    tree[node] = tree[right] + tree[left];
    

}

void update(int node,int b,int e,int i,int newvalue)
{
    if(i > e || i < b)
        return;
    if(b >= i && e <= i)
    {
        tree[node] = newvalue;
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node] = tree[left] + tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(i > e || j < b)
        return 0;
    if( b >= i && e <= j)
        return tree[node];

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return p1 + p2;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1;t <= T;t++)
    {
        int n,q;
        memset(arr,0,sizeof(arr));

        cin >> n >> q;
        for(int i = 1;i <= n;i++)
        {
            cin >> arr[i];
        }

        init(1,1,n);

        cout << "Case " << t << ":" << endl;

        for(int i = 1;i <= q;i++)
        {
            int q;
            cin >> q;
            if(q == 1)
            {
                int k,a;
                cin >> k;
                cout << arr[k+1] << endl;
                a = arr[k+1];
                arr[k+1] = 0;
                update(1,1,n,k+1,0);
            }
            if(q == 2)
            {
                int k,v,a;
                cin >> k >> v;
                arr[k+1] += v;
                a = arr[k+1];
                update(1,1,n,k+1,a);
            }
            if(q == 3)
            {
                int l,r;
                cin >> l >> r;
                cout << query(1,1,n,l+1,r+1) << endl;
            }

        }
    }
}