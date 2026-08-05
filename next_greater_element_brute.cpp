#include<iostream>
#include<vector>
using namespace std;
vector<int> next_greater_element(vector<int>&number){
	vector<int> result(number.size());
	for(int i=0;i<number.size();i++){
		bool filled=false;
		for(int j=i+1;j<number.size();j++){
			if(number[j]>number[i]){
				result[i]=number[j];
				filled=true;
				break;
			}
		}
		if(filled==false){
			result[i]=-1;
		}
	}
	return result;
}
int main(){
	int n;
	cout<<"enter size of array\n";
	cin>>n;
	int ele;
	vector<int>number;
	for(int i=0;i<n;i++){
		cout<<"enter element "<<i+1<<endl;
		cin>>ele;
		number.push_back(ele);
	}
	vector<int> result=next_greater_element(number);
	for(int ele:result){
	    cout<<ele<<endl;
	}
	return 0;
}
