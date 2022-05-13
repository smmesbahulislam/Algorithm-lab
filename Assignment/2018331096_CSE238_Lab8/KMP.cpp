//JUDGE_ID: 323675HR
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

vector<int> generatelps(string s)
{
    vector<int>lps(s.size());
    int  i=1,j=0;
    while(i<s.size())
    {
        if( s[i]==s[j])
        {
            lps[i]=j+1;

            i++;

            j++;
        }
        else if(j>0)j=lps[j-1];
        else ++i;
    }
    return lps;
}

void kmp(string text, string pat)
{
    int M = pat.size();
    int N = text.size();
    vector<int>lps;
    lps = generatelps(pat);
    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pat[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            cout<<"found pattern at "<<i-j<<'\n';
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != text[i])
        {
            if (j)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main()
{
    setIO();

    
    string text,pat;
    cin>>text>>pat;
    kmp(text,pat);
    return 0;
}