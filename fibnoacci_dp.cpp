#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n<=1){
        return n;
    }
    int first=0;
    int second=1;
    for(int i=2;i<=n;i++){
        int curr=first+second;
        first=second;
        second=curr;
    }
    return second;
}
int main(){
    int n;
    cout<<"Enter which place fibonacci number you want\n";
    cin>>n;
    cout<<fib(n);
    return 0;
}
