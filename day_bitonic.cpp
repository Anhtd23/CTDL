#include<bits/stdc++.h>
using namespace std;
long long down[1002];
long long up[1002];
long long bitonic(long long a[], int n){
    down[0] = down[n+1] = up[0] = up[n+1] = 0;
    for(int i = 1 ; i <= n ; i++){
            down[i] = a[i];
            long long tmp = 0 ;
            for(int j = i - 1; j >= 1; j--){
                if(a[i] > a[j] ) {
                    tmp = max(tmp , down[j]);
                }
            }
            down[i] += tmp;
    }
    for(int i = n ; i > 0 ; i--){
            up[i] = a[i];
            long long tmp = 0 ;
            for(int j = i + 1; j <= n; j++){
                if(a[i] > a[j] ) {
                    tmp = max(tmp , up[j]);
                }
            }
            up[i] += tmp;
    }
    long long maxA = 0;
    for(int i = 1 ; i <= n ; i++){
        maxA = max(maxA, down[i] + up[i] - a[i]);
    }
    return maxA;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        long long a[n+1];
        for(int i = 1 ; i <= n ; i++) cin>>a[i];
        cout<<bitonic(a, n)<<endl;
    }
    

    return 0;
}