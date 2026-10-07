#include<bits/stdc++.h>
using namespace std;
int longestincreasingsequence(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int main(){
    int n;
    cout<<"enter the size of array\n";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Longest Increasing sequence "<<longestincreasingsequence(nums);
    return 0;
}