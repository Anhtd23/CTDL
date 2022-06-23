#include<bits/stdc++.h>
using namespace std;
int a[15];
int n, k;
int ans = 0;
int sumA;
void devide(int sum, int i, int group){
    if(group > k ) return;   
    if(i == n){
        if(group == k ) ans++;
        return;
    }
    if(i < n - (k - group)) {
        devide(sum+ a[i], i+1,group);
        if(sum + a[i] == sumA ) devide(0, i+1,group+1);
    }
}
int main(){    
    cin>>n>>k;
    int sum = 0;
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    for(int i = 0 ; i < n ; i++) sum += a[i];
    if(sum % k != 0 ){
        cout<<0;
    }
    else {
        sumA = sum / k;
        devide(0, 0, 1);
        cout<<ans;
    }
    return 0;
}