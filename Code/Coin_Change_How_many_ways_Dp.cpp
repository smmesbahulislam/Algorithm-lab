#include<bits/stdc++.h>
using namespace std;

int count(int S[],int amount,int coins)
{

    int table[coins+1][amount+1];
    
    for(int i = 0;i <= amount;i++)
        table[0][i] = 0;

    for(int i = 0;i <= coins;i++)
        table[i][0] = 1;
    
    
    for(int i = 1;i <= coins;i++)
        for(int j = 0;j <= amount;j++)
        {
            if(S[i] > j)
                table[i][j] = table[i-1][j];
            
            else
                table[i][j] = table[i-1][j] + table[i][j-S[i]];
        }
    
    return table[coins][amount];
}


int main()
{
    int coins,amount;
    cin >> coins >> amount;
    int arr[coins];
    for(int i = 1;i <= coins;i++)
        cin >> arr[i];
    
    cout << count(arr,amount,coins);
}

/*
Sample input: 
4 15
2 3 5 10
Sample output:
9
*/