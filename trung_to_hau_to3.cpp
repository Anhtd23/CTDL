#include<bits/stdc++.h>
using namespace std;
int level(char a){
    switch (a)
    {
    case '(':
        return 0;
    case ')':
        return 4;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
void inToPos(string a){
    stack<char>c;
    int len = a.length();
    for(int i = 0 ; i < len; i++){
        if(a[i] == ' ') continue;
        if(level(a[i]) == 0) c.push(a[i]);
        else if(level(a[i]) == -1){
            cout<<a[i];
        }
        else if(level(a[i]) == 1 || level(a[i]) == 2 || level(a[i]) == 3){
            if(c.empty()) c.push(a[i]);
            else{
                    while (!c.empty() && level(a[i]) <= level(c.top()) )
                    {
                        cout<<c.top();
                        c.pop();
                    }
                    c.push(a[i]);
            }
        }
        else{
            while (level(c.top()) != 0)
            {
                cout<<c.top();
                c.pop();
            }
            c.pop();
        }
    }
    while (!c.empty())
    {
        if(c.top() == '(') break;
        cout<<c.top();
        c.pop();
    }
}
int main(){
    int t;
    cin>>t;
    cin.ignore(1);
    while (t--)
    {
        string a;
        getline(cin, a);
        //transform(a.begin(), a.end(), a.begin(), :: toupper);
        inToPos(a);
        cout<<endl;
    }
    

    return 0;
}