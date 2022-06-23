#include<math.h>
#include<iostream>
using namespace std;
long long p = 1000000007;
long long pow(long long n, long long m){
    if( m == 0) return 1;
    long long x = pow(n, m/2);
    if( m % 2 == 0 ) return (x * x ) % p;
    else return (x * x  * n) % p;
}
int main()
{
    long long n, m;
    int count;
    cin>>count;
    while( count--){
        cin>>n>>m;
        cout<<pow(n, m)<<endl;
    }
    return 0;  
}
