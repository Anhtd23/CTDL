#include<bits/stdc++.h>
using namespace std;
long long p = 1e15+7;
long long chiaDu( long long a, long long b){
        if(a == 0 ) return 0;
        if( a == 1 ) return b;
        if( a % 2 == 0 ) return (2 * (chiaDu(a/2, b)%p)) %p;    
        else return (2 * (chiaDu(a/2, b)%p) + b) %p; 
    }
int main(){
    int a = 20;//10100
    int b = 30;//11110
    
    cout<<(b & ~a);
    return 0;
}