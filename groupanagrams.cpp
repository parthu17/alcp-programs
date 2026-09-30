#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> groupanagrams(vector<string> &words){
    unordered_map<string,vector<string>> map;
    for(string word: words){
        string key = word;
        sort(key.begin(),key.end());
        map[key].push_back(word);
    }
    vector<vector<string>> result;
    for(auto &pair:map){
        result.push_back(pair.second);
    }
    return result;
}
int main(){
    int n;
    cout<<"enter size of input array\n";
    cin>>n;
    vector<string>words(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i+1<<" string\n";
        cin>>words[i];
    }
    vector<vector<string>> result=groupanagrams(words);
    for(vector<string> arr : result){
        cout<<"[";
        for(string st: arr){
            cout<<st<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}