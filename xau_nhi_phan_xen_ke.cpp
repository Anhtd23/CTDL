#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    a[0] = 0;
    cout<<a[0]<<" ";
    for(int i = 1 ; i < n ; i++) {
        if(a[i-1] == 0 ){
            a[i] = 1;
            cout<<a[i]<<" ";
        }
        else {
            a[i] = 0;
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
    int b[n];
    b[0] = 1;
    cout<<b[0]<<" ";
    for(int i = 1 ; i < n ; i++) {
        if(b[i-1] == 0 ){
            b[i] = 1;
            cout<<b[i]<<" ";
        }
        else {
            b[i] = 0;
            cout<<b[i]<<" ";
        }
    }
    return 0;
}