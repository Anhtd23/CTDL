#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int count = 1;
        cout<<'1'<<" ";
        queue<string> q;
        q.push("1");
        while (count < n)
        {
            string tmp = q.front();
            string tmp1 = tmp + "0";
            cout<<tmp1<<" ";
            q.push(tmp1);
            count++;
            if(count >= n) break;
            string tmp2 = tmp + "1";
            cout<<tmp2<<" ";
            count++;
            q.push(tmp2);
            q.pop();
        }
        cout<<endl;
    }
        

    return 0;
}