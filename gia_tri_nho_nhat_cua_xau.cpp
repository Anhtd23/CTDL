#include<bits/stdc++.h>
using namespace std;
int mark[150];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        string a;
        cin>>n>>a;
        int len = a.length();
        for(int i = 0 ; i < len; i++) mark[a[i]]++;
        priority_queue<int> q;
        for(int i = 'A' ; i <= 'z' ; i++){
            if(mark[i] > 0 ){
                q.push(mark[i]);
                mark[i] = 0;
            }
        }
        while (n--)
        {
            
            int tmp = q.top();
            tmp--;
            q.pop();
            q.push(tmp);
        }
        long long sum = 0;
        while (!q.empty())
        {
            sum += (long long)(pow(q.top(), 2));
            q.pop();
        }
        cout<<sum<<endl;
    }
    return 0;
}