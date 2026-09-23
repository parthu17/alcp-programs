#include<bits/stdc++.h>
using namespace std;
int matrix_mul(vector<int> &p,int n){
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int len=2;len<n;len++){
        for(int i=1;i<=n-len;i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int cost=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                if(cost<dp[i][j]){
                    dp[i][j]=cost;
                }
            }
        }
    }
    return dp[1][n-1];
}
int main(){
    int n;
    cout<<"Enter number of matrices\n";
    cin>>n;
    vector<int>p(n+1);
    cout<<"Enter dimensions of the matrices in the order p[i-1] x p[i]\n";
    for(int i=0;i<=n;i++){
        cin>>p[i];
    }
    cout<<matrix_mul(p,n);
    return 0;
}
