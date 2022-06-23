#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> c;
    while (true)
    {
        string a;
        cin>>a;
        if(a == "push"){
            int n;
            cin>>n;
            c.push(n);
        }
        else if(a == "pop") c.pop();
        else {
            if(c.empty()) 
            {
                cout<<"empty";
                break;
            }
            else {
                stack <int> b;
                while (!c.empty())
                {
                    b.push(c.top());
                    c.pop();
                }
                while (!b.empty())
                {
                    cout<<b.top()<<" ";
                    c.push(b.top());
                    b.pop();
                }
            }
            cout<<endl;
        }
    }
    

    return 0;
}