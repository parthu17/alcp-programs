#include<bits/stdc++.h>
using namespace std;
int climb_stairs(int n){
    if(n<=1){
        return n;
    }
    int onestep=1;
    int twostep=1;
    for(int i=3;i<=n;i++){
        int currstep=onestep+twostep;
        onestep=twostep;
        twostep=currstep;
    }
    return twostep;
}

int main(){
    int n;
    cout<<"Enter the step whose number of ways you want\n";
    cin>>n;
    cout<<climb_stairs(n);
    return 0;
}
