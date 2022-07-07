#include<bits/stdc++.h>
using namespace std;

int a[100005];
int tree[400005];

void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node] = a[b];
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;
    
    init(left,b,mid);
    init(right,mid+1,e);

    tree[node] = min(tree[left],tree[right]);

}

int query(int node,int b,int e,int i,int j)
{
    if(i > e || j < b)
        return INT_MAX;
    if(b >= i && e <= j)
    {
        return tree[node];
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;
    
    int x = query(left,b,mid,i,j);
    int y = query(right, mid + 1,e,i,j);

    return min(x,y);
}


int main()
{
    int t,n,qs,x,y;
    cin >> t;
    for(int cs = 1;cs <= t;cs++){
        cin >> n >> qs;

        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }

        init(1,1,n);

        cout << "Case " << cs << ":" << endl;

        for(int i = 0;i < qs;i++){
            cin >> x >> y;

            cout << query(1,1,n,x,y) << endl;
        }
    }

}