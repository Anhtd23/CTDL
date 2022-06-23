#include<bits/stdc++.h>
using namespace std;
void lonHonPhai(int a[], int n){
    stack<int > c;
    c.push(a[n-1]);
    int b[n];
    b[n-1] = -1;
    for(int i = n-2 ; i >= 0 ; i--){
        if(a[i] >= c.top()){
            while (!c.empty() && a[i] >= c.top()) c.pop();
        }
        if(!c.empty()) b[i] = c.top();
        else b[i] = -1;
        c.push(a[i]);
    }
    for(int i = 0 ; i < n ; i++) cout<<b[i]<<" ";
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++ ) cin>>a[i];
        lonHonPhai(a, n);
    }
    
    return 0;
}