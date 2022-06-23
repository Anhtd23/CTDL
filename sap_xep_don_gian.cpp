#include<bits/stdc++.h>
using namespace std;
int a[100001];
int countA[100001];
int minSwap(int a[], int n){
    for(int i = 0 ; i < n ; i++){
        if(a[i] == 1 ){
            countA[1] = 1;
            continue;
        }
        else{
            countA[a[i]] = countA[a[i]-1]+1;
        }
    }
    return n - *max_element(countA+1, countA + n +1);
}
int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    cout<<minSwap(a, n);
    return 0;
}