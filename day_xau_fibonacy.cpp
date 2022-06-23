#include<bits/stdc++.h>
using namespace std;
long long n, k;
long long a[94];
void init(){
    a[1] = 1;
    a[2] = 1;
    for(int i = 3 ; i <= 93; i++) a[i] = a[i-1] + a[i-2];
}
char pos(int i){
    if( i == 1 ) return '0';
    if( i == 2) return '1';
    if( k <= a[i-2] ){
        return pos(i-2);
    }
    else {
        k -= a[i-2];
        return pos(i-1);
    }
}
int main(){
    int t;
    cin>>t;
    init();
    while (t--)
    {
        cin>>n>>k;
        int i = 0;
        cout<<pos(n-1)<<endl;
    }
    return 0;
}