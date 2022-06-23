#include<bits/stdc++.h>
using namespace std;
int cal(int n){
    int count = 0;
    for(int i = 1; i <= n ; i++){
        count += (int)pow(2, i);
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int limit = cal(n);
        queue<string> q;
        q.push("6");
        q.push("8");
        stack<string> c;
        c.push("6");
        c.push("8");
        int count = 2;
        cout<<limit<<endl;
        while(true){
            string tmp = q.front();
            string tmp1 = tmp + "6";
            string tmp2 = tmp + "8";
            c.push(tmp1);c.push(tmp2);
            q.push(tmp1);
            q.push(tmp2);
            count += 2;
            q.pop();
            if(count == limit) break;
        }
        
        while (!c.empty())
        {
            cout<<c.top()<<" ";
            c.pop();
        }
        cout<<endl;
    }
    
    return 0;
}