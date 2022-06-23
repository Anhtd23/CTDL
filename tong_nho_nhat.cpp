#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        sort(a, a+n);
        string b = "", c = "";
        b += (a[0]+48);c += (a[1] + 48);
        int check = true;
        for(int i = 2; i < n ; i++){
            if(check) {b += (a[i] + 48); check = 0;}
            else {c += (a[i]+48); check = 1;};
        }
        long long x, y;
        stringstream ss(b);
        stringstream ss2(c);
        ss>>x;
        ss2>>y;
        cout<<x + y<<endl; 
    }
    
    return 0;
}