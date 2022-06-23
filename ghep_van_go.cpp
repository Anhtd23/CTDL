#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int n;
long long solve(){
    long long ans = 0;
    stack<long long> c;
    long long i = 0, t = 0;
    while(i < n){
        if(c.empty() || (a[i] >= a[c.top()])) c.push(i++); 
        else {
            long long tmp = c.top();
            c.pop();
            if(c.empty()){
                if(a[tmp] <= i) t = a[tmp];
            }
            else{
                if(a[tmp] <= i - c.top() - 1 ) t = a[tmp];
            }
            if(t > ans ) ans = t;
        } 
    }
    while (!c.empty())
    {
            long long tmp = c.top();
            c.pop();
            if(c.empty()){
                if(a[tmp] <= i) t = a[tmp];
            }
            else{
                if(a[tmp] <= i - c.top() - 1 ) t = a[tmp];
            }
            if(t > ans ) ans = t;
    }
    //if(ans == 0 ) return -1;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) {
            cin>>a[i];
        } 
        cout<<solve()<<endl;
    }
    return 0;
}