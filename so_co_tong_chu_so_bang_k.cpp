#include<bits/stdc++.h>
using namespace std;
long long p = 1000000007;
long long a[101][50001];
int sumEqualK(int n , int k){
    
    for(int i = 2 ; i <= n ; i++){
        for(int j = 2 ; j <= k ; j++){
            a[i][j] = 0;
            for(int t = 0 ; t <= 9 ; t++){
                if(j - t >= 0) a[i][j] = (a[i][j] + a[i-1][j-t])%p;
                else break;
            }
        }
    }
    return a[n][k];
}
int main(){
    int t;
    cin>>t;
    for(int i = 1 ; i < 10 ; i++){
        a[1][i] = 1;
    }
    for(int i = 10 ; i <= k ; i++) a[1][i] = 0;
    for(int i = 1 ; i <= 100; i++) a[i][1] = 1;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        cout<<sumEqualK(n, k)<<endl;
    }
    
    return 0;
}