#include<bits/stdc++.h>
using namespace std;

int count(vector<int> &S,int amount,int coins)
{
    int table[coins+1][amount+1];
    
    for(int i = 0;i <= amount;i++)
        table[0][i] = 0;
    for(int i = 0;i <= coins;i++)
        table[i][0] = 0;
    
    for(int i = 1;i <= coins;i++)
        for(int j = 0;j <= amount;j++)
        {
            if(S[i]>j)
                table[i][j] = table[i-1][j];
            else
            {
                if(i == 1 && (j % S[i] == 0))
                    table[i][j] = j / S[i];
                else
                    table[i][j] = min(table[i-1][j],1+table[i][j-S[i]]);
       
            }
        }

    return table[coins][amount];
}

int main()
{
    int coins,amount;
    cin >> coins >> amount;
    vector<int> arr(coins);
    for(int i = 1;i <= coins;i++)
        cin >> arr[i];

    sort(arr.begin(),arr.end()+1);
    
    cout << count(arr,amount,coins) << endl;
    return 0;
}

/*
Sample input:
4 10
1 5 6 9
Sample output:
2

*/