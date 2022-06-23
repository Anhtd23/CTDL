#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    stack <int> c;
    while (t--)
    {
        string a;
        cin>>a;
        if(a == "PUSH"){
            int n;
            cin>>n;
            c.push(n);
        }
        else if( a == "POP"){
            if(!c.empty()) c.pop();
        }
        else {
            if(c.empty()) 
            {
                cout<<"NONE";
            }
            else {
                cout<<c.top();
            }
            cout<<endl;
        }
    }
    return 0;
}