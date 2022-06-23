#include<bits/stdc++.h>
using namespace std;
int n;
long long m = 1000000007;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ;i++) cin>>a[i];
        sort(a, a+n);
        long long max = 0;
        for(int i = 0 ; i < n ; i++){
            max = (max + a[i] * i) % m;
        }
        cout<<max<<endl;
    }
    
}