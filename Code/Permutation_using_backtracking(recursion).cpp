#include<bits/stdc++.h>
using namespace std;

void permutation(string s,int l,int r){
    if(l == r)
        cout << s << endl;
    else
    {
        for(int i = l;i <= r;i++)
        {
            swap(s[l],s[i]);
            permutation(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}

int main(){
    string str;
    cin >> str;
    int n = str.length();
    permutation(str,0,n-1);
    return 0;
}