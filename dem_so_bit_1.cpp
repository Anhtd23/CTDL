#include<bits/stdc++.h>
using namespace std;
long long store[52];
long long findMoc(long long n){
    for(int i = 0 ; i < 52 ; i++){
        if(store[i] >= n ) return store[i];
    }
    return 0;
}
long long countBit1(long long n, long long l, long long r){
    if(n )
    if(n == 1 ) return 1;
    long long k = findMoc(n);
    long long mid = k/2;
    long long x1;
    long long x2;
    if( r == mid + 1 && l == mid + 1){
        return n % 2;
    }
    if(l == mid + 1 ) return countBit1(n, l + 1 , r) + n%2;
    if(r == mid + 1 ) return countBit1(n, l, r-1) + n % 2;
    if(l > mid + 1 ) return countBit1(n/2, l-mid-1, r-mid-1);
    if(r <= mid) return countBit1(n/2, l, r );
    return countBit1(n/2, l, mid) + countBit1(n/2, 1, r-mid-1) + n%2;
}
int main(){
    int t;
    cin>>t;
    for(int i = 1 ; i < 52 ; i++){
        store[i] = store[i-1] * 2 + 1;
    }
    while (t--)
    {
        long long n, l , r;
        cin>>n>>l>>r;
        cout<<countBit1(n, l, r)<<endl;
    }
    

    return 0;
}