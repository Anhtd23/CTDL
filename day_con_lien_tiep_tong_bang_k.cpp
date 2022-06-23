#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int n;
long long k;
bool checkSum(){
    int l = 0, r = 0;
    long long sum = 0;
    for(r = 0 ; r < n ; r++){
        sum += a[r];
        if(sum == k) return true;
        if(sum > k){
            while(sum > k && l < r){
                sum -= a[l];
                if(sum == k) return true;
                l++;
            }
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        if(checkSum()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}