#include<bits/stdc++.h>
using namespace std;
int x, y, z;
int a[200];
int  minSwap(int n){
	a[1] = x;
	for(int i = 2 ; i <= n ; i++){
		int minA = a[i-1] + x; 
		int j;
		if(i % 2 == 0 ){
			j = i/2;
			minA = min(minA, a[i/2] + z);
		}
		else {
			j = i/2 + 1;
		}
		while(j < i){
			minA = min(minA, a[j] + z + y *(2 * j - i));
			j++;
		}
		a[i] = minA;
	}
	//for(int i = 0 ; i <= n ; i++) cout<<a[i]<<" ";
	return a[n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cin>>x>>y>>z;
		cout<<minSwap(n)<<endl;		
	}
	return 0;
}
