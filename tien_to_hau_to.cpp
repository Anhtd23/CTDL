#include<bits/stdc++.h>
using namespace std;
bool isOperator(char a){
    if( a =='+' || a =='-' || a == '*' || a== '/' || a == '%') return true;
    else return false;
}
string inToPre(string a){
    stack<string> c;
    int len =  a.length();
    for(int i = len-1; i >= 0; i--){
        if(isOperator(a[i])){
            string tmp1 = c.top(); c.pop();
            string tmp2 = c.top(); c.pop();
            string tmp3 = tmp1 + tmp2 + a[i];
            c.push(tmp3);
        }
        else{
            string tmp = "";
            tmp += a[i];
            c.push(tmp);
        }
    }
    return c.top();
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        cout<<inToPre(a)<<endl;
    }
    


    return 0;
}