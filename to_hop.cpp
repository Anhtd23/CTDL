#include<bits/stdc++.h>
using namespace std;
int D[1000][1000] = {0};
long long p = 1000000007;
void init(){
    for(int i = 0; i < 1000; i++){
        D[0][i] = 1;
        D[i][i] = 1;
    }
    for(int i = 0 ; i < 1000 ; i++) D[1][i] = i;
}
int C(int x, int n){
    if( D[x][n]) return D[x][n];
    else{
        long long y = C(x, n-1) + C(x-1, n-1);
        D[x][n] = y % p;
        return D[x][n];
    }
}

int main(){
    int t;
    cin>>t;
    init();
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        cout<<C(k, n)<<endl;
    }
    

    return 0;
}