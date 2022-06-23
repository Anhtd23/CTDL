#include<bits/stdc++.h>
using namespace std;
int a[30];
int n, k;
int ans = 1000;
void Try(int i, int sum, int soTo){
    if(sum == k && soTo < ans) ans = soTo;
    if(sum < k && i < n){
        for(int j = i ; j < n  ; j++){
            if( sum + a[j] <= k ) Try(j + 1, sum + a[j], soTo + 1);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ans = 1000;
        cin>>n>>k;   
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        sort(a, a+n, greater<>());
        Try(0, 0, 0);
        if(ans != 1000) cout<<ans<<endl;
        else cout<<"-1"<<endl;
    }
    
    return 0;
}