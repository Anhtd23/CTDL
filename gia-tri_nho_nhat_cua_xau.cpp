#include<bits/stdc++.h>
using namespace std;
long long minValue(string a, int k){
    priority_queue<int>q;
    int len = a.length();
    int mark[150]={0};
    for(int i = 0 ; i < len;i++){
        mark[a[i]]++;
    }
    for(int i = 'A'; i <= 'Z'; i++) {
        if(mark[i] > 0 ){
            q.push(mark[i]);
        }
    }
    while (k > 0 )
    {
        int tmp1 = q.top();
        q.pop();
        tmp1--;
        if(tmp1 > 0 ) q.push(tmp1);
        k--;
    }
    long long sum = 0;
    while (!q.empty())
    {
        sum += ((long long)q.top() * (long long)q.top());
        q.pop();
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int k;
        cin>>k;
        string a;
        cin>>a;
        cout<<minValue(a, k)<<endl;
    }
    

    return 0;
}