#include<bits/stdc++.h>
using namespace std;

int coinchange(vector<int>&coins_arr,int amount,int coins,vector<vector<int> > &dp)
{
    if(amount == 0)
        return dp[coins][amount] = 1;
    
    if(coins == 0)
        return 0;
    
    if(dp[coins][amount] != -1)
        return dp[coins][amount];
    
    if(coins_arr[coins-1] <= amount)
    //either pick this coin or not
        return dp[coins][amount] = coinchange(coins_arr,amount - coins_arr[coins-1],coins,dp) + coinchange(coins_arr,amount,coins-1,dp);
    else//we have no option but to leave this coin
        return dp[coins][amount] = coinchange(coins_arr,amount,coins-1,dp);

}

int main()
{
    int tc = 1;
    while(tc--){
    int coins,amount;
    cin >> coins >> amount;
    vector<int> coins_arr(coins);
    vector<vector<int> > dp(coins+1,vector<int>(amount+1,-1));

    for(int i = 0;i < coins;i++ )
        cin >> coins_arr[i];
    

    int result = coinchange(coins_arr,amount,coins,dp);
    cout << result << endl;
    }
    return 0;
}

