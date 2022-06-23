#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    queue<int> q;
    while (t--)
    {
        string a;
        cin>>a;
        if(a == "PUSH"){
            int tmp;
            cin>>tmp;
            q.push(tmp);
        }
        else if(a == "POP"){
            if(!q.empty()) q.pop();
        }
        else {
            if(!q.empty()) cout<<q.front()<<endl;
            else cout<<"NONE"<<endl;
        }
    }
    
    return 0;
}