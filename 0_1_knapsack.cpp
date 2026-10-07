#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> &weights,vector<int> &values,int n, int W){
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(weights[i-1]>w){
                dp[i][w]=dp[i-1][w];
            }
            else{
                dp[i][w]=max(dp[i-1][w],(dp[i-1][w-weights[i-1]]+values[i-1]));

            }
        }
    }
    return dp[n][W];

}
int main(){
    int n;
    cout<<"Enter the number of items\n";
    cin>>n;
    vector<int>values(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i+1<<" value";
        cin>>values[i];
    }
    vector<int> weights(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i+1<<" weight";
        cin>>weights[i];
    }
    int W;
    cout<<"Enter the weight of knapsack\n";
    cin>>W;
    cout<<"Max profit using 0/1 knapsack is "<<knapsack(weights,values,n,W);
    return 0;
}