#include<bits/stdc++.h>
using namespace std;
string toString(char a){
    string tmp = "";
    tmp += a;
    return tmp;
}
string incString(string a){
    int len = a.length();
    for(int i = 0 ; i < len ; i++){
        a[i]++;
    }
    return a;
}
void expIncDec(string a){
    int n = a.length();
    stack<string> c;
    if(a[0] == 'D') c.push("21");
    if(a[0] == 'I') c.push("12");
    int max = 2, min = 0;
    for(int i = 1 ; i < n; i++){
        if(a[i] == 'D' ){
                string tmp = c.top();
                c.pop();
                tmp = incString(tmp);
                char x = min + 1 + '0';
                tmp += x;
                c.push(tmp);
        }
        else{
            char x = max + 1 + '0';
            cout<<c.top();
            string tmp  = "";
            tmp += x;
            c.push(tmp);
            min = i + 1;
        }
        max++;
    }
    cout<<c.top();
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        expIncDec(a);
    }
    return 0;
}