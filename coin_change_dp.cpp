#include<bits/stdc++.h>
using namespace std;
int coin_change(vector<int>&coins,int amount){
    vector<int> dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        for(int c: coins){
            if(c<=i && dp[i-c]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-c]+1);
            }
            
        }
    }
    return (dp[amount]==INT_MAX)?-1:dp[amount];
}
int main(){
    int amount;
    cout<<"enter the amount\n";
    cin>>amount;
    int n;
    cout<<"enter number of coin denominations\n";
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i+1<<" denomination\n";
        cin>>coins[i];
    }
    cout<<coin_change(coins,amount);
    return 0;
}
