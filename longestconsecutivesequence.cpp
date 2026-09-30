#include<bits/stdc++.h>
using namespace std;
int longestconsecutive_sequence(vector<int> &arr){
    unordered_set<int> numset(arr.begin(),arr.end());
    int longest=0;
    for(int x : numset){
        if(numset.find(x-1)==numset.end()){
            int length=1;
            while(numset.find(x+length)!=numset.end()){
                length++;
            }
            longest=max(longest,length);
        }
    }
    return longest;
}
int main(){
    int n;
    cout<<"enter size of the array\n";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i+1<<" element\n";
        cin>>arr[i];
    }
    cout<<longestconsecutive_sequence(arr);
    return 0;

}