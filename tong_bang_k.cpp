#include<bits/stdc++.h>
using namespace std;
long long mark[1005];
int p = 1e9 + 7;
long long countEqualK(vector<int> a, int k){
    int n = a.size();
    for(int i = 1 ;  i <= k ; i++){
        mark[i] = 0;
        for(int j = 0 ; j < n ; j++){
            if( i - a[j] >= 0 ){
                mark[i] = (mark[i] + mark[i-a[j]]) % p;
            }
        }
    }
    return mark[k];
}
int main(){
    int t;
    cin>>t;
    mark[0] = 1;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        cout<<countEqualK(a, k)<<endl;
    }
    return 0;
}