#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int factorial = 1;
    for(int i = 2;i <= n;i++){
        factorial = factorial * i;
    }
    return factorial;
}

int nCr(int n,int r){
    return factorial(n)/(factorial(r) * factorial(n-r));
}

int main(){
    int n,r;
    cin >> n >> r;
    cout << nCr(n,r) << endl;
}