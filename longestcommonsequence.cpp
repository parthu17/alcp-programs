#include<bits/stdc++.h>
using namespace std;
int longestcommonsequence(string &a,string &b){
    int m = a.size();int n=b.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){
                dp[i][j]=1+dp[i-1][j-1];

            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main(){
    string a;
    cout<<"enter the first string\n";
    cin>>a;
    string b;
    cout<<"enter the second string\n";
    cin>>b;
    cout<<"Longest common sequence is of the size: "<<longestcommonsequence(a,b);
    return 0;
}