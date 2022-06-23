#include<bits/stdc++.h>
using namespace std;
long long p = 1000000007;
int numberWay(int n, int k){
    int a[n+1] = {0};
    a[0] = 1; a[1] = 1;
    for(int i = 2; i <= n ; i++){
        for(int j = 0 ; j <= k && j <= i ; j++){
            a[i] = (a[i-j] + a[i]) % p;
        }
    }
    return a[n];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        cout<<numberWay(n , k)<<endl;
    }
    return 0;
}