#include<bits/stdc++.h>
using namespace std;
int n;
int a[60];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int b[n];
        for(int i = 0 ; i <n ; i++) cin>>a[i];
        for(int i = 0 ; i < n ; i++) b[i] = a[i];
        sort(a, a + n);
        bool check = true;
        for(int i = 0 ; i < n ; i++){
            if(b[i] != a[i] && b[i] != a[n-i-1]){
                check = false;
                break;
            }
        }
        if(check) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    

    return 0;
}