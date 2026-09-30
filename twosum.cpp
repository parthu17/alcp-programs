#include<bits/stdc++.h>
using namespace std;
vector<int> two_sum(vector<int> &arr,int target){
    unordered_map<int,int> map;
    for(int i=0;i<arr.size();i++){
        int complement = target - arr[i];
        if(map.find(complement)!=map.end()){
            return {map[complement],i};
        }
        map[arr[i]]=i;
    }
    return {};
}
int main(){
    int n;
    cout<<"enter the size of the array\n";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i+1<<" element\n";
        cin>>arr[i];
    }
    int target;
    cout<<"enter the target element\n";
    cin>>target;
    vector<int> result = two_sum(arr,target);
    for(int ele: result){
        cout<<ele<<" ";
    }
    return 0;

}