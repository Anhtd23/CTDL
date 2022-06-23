#include<bits/stdc++.h>
using namespace std;
long long mu2(int n){
    if(n == 0 ) return 1;
    long long x = mu2(n/2);
    if(n % 2 == 0 ) return x * x;
    else return x * x * 2;
}
int pos(int n, long long k){
    for(int i = 1 ; i <= n; i++){
        if( (k - mu2(i-1)) % mu2(i) == 0){
            return i;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {   int n;
        long long  k;
        cin>>n>>k;
        cout<<pos(n, k)<<endl;
    }
    
    return 0;
}