#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int p[5]= {0,1,2,5,6};
    // int wt[5]={0,2,3,4,5};
    // int capacity = 8,num_of_object = 4;
    // int k[5][9];
    
    int capacity , num_of_object;
    cin >> capacity >> num_of_object;
    int p[num_of_object + 1];
    int wt[num_of_object + 1];
    p[0] = 0;
    wt[0] = 0;
    for(int i = 1;i < 5;i++){
        cin >> p[i];
        cin >> wt[i];
    }
    int k[num_of_object+1][capacity+1];


    for(int i = 0;i <= num_of_object;i++)
    {
        for(int w=0;w <= capacity;w++)
        {
            if(i == 0 || w == 0)
                k[i][w] = 0;
            else if(wt[i] <= w)
                k[i][w] = max((p[i]+k[i-1][w-wt[i]]),k[i-1][w]);
            else
                k[i][w] = k[i-1][w];
        }
    }
    cout << k[num_of_object][capacity]<<endl;

    int i = num_of_object;
    int j = capacity;
    while(i > 0 && j >= 0)
    {
        if(k[i][j] == k[i-1][j])
        {
            cout << i << " = 0" << endl;
            i--;
        }
        else
        {
            cout << i << " = 1" << endl;
            j = j - wt[i];
            i--;
            // cout << "value of i = " << i << " and value of j = " << j << endl;
        }
    }
}