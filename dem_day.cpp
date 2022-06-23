#include<bits/stdc++.h>
using namespace std;
long long p = 123456789;
long long mu2(long long n){
    if(n == 0 ) return 1;
    long long x = mu2(n/2);
    if(n % 2 == 0 ) return (x * x) % p;
    else return (x * x * 2) % p;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        cout<<mu2(n-1)<<endl;
    }
    return 0;
}