#include<bits/stdc++.h>
using namespace std;
int a[15];
int D[15];
int n;
void print(int n){
    cout<<"("<<a[1];
    for(int i = 2 ; i <= n ; i++) cout<<" "<<a[i];
    cout<<") ";
}
void Try(int i){
    for(int j = a[i-1] ; j >= 1; j--){
        a[i] = j;
        D[i] = D[i-1] + j;
        if(D[i] == n) print(i);
        else if(D[i] < n) Try(i+1);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        a[0] = n;
        D[0] = 0;
        Try(1);
        cout<<endl;
    }
    return 0;
}