#include<bits/stdc++.h>
using namespace std;
long long  p = 1000000007;
long long pow(long long n, long long m){
    if( m == 0) return 1;
    long long x = pow(n, m/2);
    if( m % 2 == 0 ) return (x * x ) % p;
    else return ((x * x)% p  * n) % p;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        stringstream ss(a);
        long long x;
        ss>>x;
        reverse(a.begin(), a.end());
        stringstream ss1(a);
        long long res;
        ss1>>res;
        cout<<pow(x, res)<<endl;
    }
    

    return 0;
}