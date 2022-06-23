#include<bits/stdc++.h>
using namespace std;
long long aMax[1000001];
long long a[1000001], n;
typedef pair<int, int> II;
void solve(){
   stack<II> c;
   c.push(II(a[0], 0));
   long long countA = a[0];
    aMax[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        while (!c.empty() && a[i] > c.top().first)
        {
            c.pop();
        }
        int k = 0;
        if(c.empty()){
            k = a[i] * (i + 1);
        }
        else {
            k = a[i] * ( i - c.top().second);
            k += aMax[c.top().second];
        }
        c.push(II(a[i], i));
        aMax[i] = k;
        countA += k;
    }
    cout<<countA<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        solve();
    }
    return 0;
}