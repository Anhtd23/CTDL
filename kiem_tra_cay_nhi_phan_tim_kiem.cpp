#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        bool check = true;
        for(int i = 0 ; i < n - 1 ; i++){
            if(a[i] > a[i+1]) {
                check = false;
                break;
            }
        }
        cout<<check<<endl;
    }

    return 0;
}