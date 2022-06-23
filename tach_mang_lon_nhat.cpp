#include<bits/stdc++.h>
using namespace std;;
int n;
long long a[100000];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int k = 0;
        cin>>n>>k;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        sort(a, a+n);
        if(k * 2 > n) k = n - k;
        long long sum1 = 0 , sum2 = 0;
        for(int i = 0 ; i < k ; i++){
            sum1 += a[i];
        }
        for(int i = k ; i < n ; i++) sum2 += a[i];
        cout<<sum2 - sum1<<endl;
    }
    return 0;
}