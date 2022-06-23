#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n;
        int a[n], b[n-1];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        for(int i = 0 ; i < n -1; i++) cin>>b[i];
        int i = 0;
        for( i = 0 ; i < n - 1; i++){
            if( a[i] != b[i] ) break;
        }
        cout<<i+1<<endl;
    }
    

    return 0;
}