#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n+1] = {0};
        a[1] = 0;
        int x, y;
        for(int i = 0 ; i < n -1; i++) {
            cin>>x>>y;
            a[y] = a[x] +1;
        }
        sort(a+1, a+n+1);
        cout<<a[n]<<endl;
    }

    return 0;
}