#include<bits/stdc++.h>
using namespace std;
long long a[2000000];
long long mark[2000002];
int main(){
    int t;
    cin>>t;
    while (t--)
    {   
        int n;
        cin>>n;
        memset(mark, 0, n * sizeof(long long));
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        mark[0] = a[0];
        mark[1] = a[1];
        mark[2] = a[0] + a[2];
        for(int i = 3 ; i < n ; i++){
            mark[i] = a[i] + max(mark[i-2], mark[i-3]);            
        }
        cout<<max(mark[n-1], mark[n-2])<<endl;
    }
    
    return 0;
}