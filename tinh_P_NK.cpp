#include<bits/stdc++.h>
using namespace std;
long long D[1000][1000];
long long p = 1000000007;
long long P(int n, int k){
    if(D[n][k] != 0) return D[n][k];
    D[n][k] = P(n, k-1) * (n - k + 1) % p;
    return D[n][k];  
}
int main(){
    int t;
    cin>>t;
    for(int i = 0 ; i < 1000; i++) D[i][0] = 1;
    for(int i = 0 ; i < 1000; i++){
        D[i][1] = i;
    }
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        cout<<P(n, k)<<endl;
    }
    

    return 0;
}