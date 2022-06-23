#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n], b[n];
        for(int i = 0; i < n ; i++) cin>>a[i];
        for(int i = 0; i < n ; i++) b[i] = a[i];
        sort(a, a+n);
        int l = 0, r = n -1;
        while (l < n)
        {
            if(b[l] != a[l] ){
                break;
            }
            l++;
        }
        while (r > l)
        {
            if(b[r] != a[r]) break;
            r--;
        }
        cout<<l+1<<" "<<r+1;
        cout<<endl;
    }
    return 0;
}