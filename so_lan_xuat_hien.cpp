#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i = 0; i < n ; i++){
            cin>>a[i];
        }
        int i = 0;
        int count = 0;
        while (a[i] <= k && i < n)
        {
            if(a[i] == k) count++;
            i++;
        }
        if(count) cout<<count;
        else cout<<"-1";
        cout<<endl;
    }
    return 0;
}