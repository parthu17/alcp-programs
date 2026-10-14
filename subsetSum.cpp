#include<bits/stdc++.h>
using namespace std;
bool issubsetsum(vector<int> &arr,int index,int remaining){
    if(remaining==0)return true;
    if(index==arr.size()||remaining<0) return false;
    if(issubsetsum(arr,index+1,remaining-arr[index])) return true;
    return issubsetsum(arr,index+1,remaining);
}
int main(){
    int n;
    cout<<"enter size of array\n";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i+1<<" element\n";
        cin>>arr[i];
    }
    int target;
    cout<<"enter target\n";
    cin>>target;
    cout<<(issubsetsum(arr,0,target)?"Subset found for the target":"No such subset found");
    return 0;
}
