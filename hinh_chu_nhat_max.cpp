#include<bits/stdc++.h>
using namespace std;
long long maxArea(long long a[], long long n){
    stack<int> c;
    long long maxArea = 0;
    int tp = 0;
    int i = 0;
    while (i < n)
    {
        if( c.empty() || a[c.top()] <= a[i]) c.push(i++);
        else{
            tp = c.top();
            c.pop();
            long long tmp = a[tp] * (c.empty() ? i : i - c.top() - 1);
            if(tmp > maxArea) maxArea = tmp;
        }
    }
    while (!c.empty())
    {
        tp = c.top();
        c.pop();
        long long tmp = a[tp] * (c.empty() ? i : i - c.top() - 1);
        if(tmp > maxArea) maxArea = tmp;
    }
    return maxArea;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        long long a[n];
        for(long long i = 0 ; i < n; i++) cin>>a[i];
        cout<<maxArea(a, n)<<endl;
    }
    
}