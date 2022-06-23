#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    deque<int> q;
    while (t--)
    {
        string a;
        cin>>a;
        if(a == "PUSHFRONT"){
            int n;
            cin>>n;
            q.push_front(n);
        }
        else if(a == "PRINTFRONT"){
            if(!q.empty()) cout<<q.front()<<endl;
            else cout<<"NONE"<<endl;
        }
        else if(a == "POPFRONT"){
            if(!q.empty()) q.pop_front();
        }
        else if( a == "PUSHBACK"){
            int n;
            cin>>n;
            q.push_back(n);
        }
        else if(a == "PRINTBACK"){
            if(!q.empty()) cout<<q.back()<<endl;
            else cout<<"NONE"<<endl;
        }
        else{
            if(!q.empty()) q.pop_back();
        }
    }
    

    return 0;
}