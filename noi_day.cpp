#include<bits/stdc++.h>
using namespace std;
int n;
long long a[2000000];
long long p = 1000000007;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        priority_queue<long long, vector<long long>, greater<long long>> q(a, a + n);
        long long sum = 0, l = 0;
        while (q.size() > 1)
        {
            long long chen = q.top();
            q.pop();
            chen += q.top();
            q.pop();
            chen %= p;
            q.push(chen);
            sum = (sum + chen) % p;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}