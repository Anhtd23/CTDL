#include<bits/stdc++.h>
using namespace std;
bool isOperator(char a){
    if( a =='+' || a =='-' || a == '*' || a== '/' || a == '%') return true;
    else return false;
}
long long calcu(string a){
    int len = a.length();
    stack<long long> c;
    for(int i = len-1; i >= 0 ; i--){
        if(isOperator(a[i])){
            int tmp1 = c.top();c.pop();
            int tmp2 = c.top();c.pop();
            int tmp3 = 0;
            if( a[i] == '+') tmp3 = tmp1 + tmp2; 
            if( a[i] == '-') tmp3 = tmp1 - tmp2; 
            if( a[i] == '*') tmp3 = tmp1 * tmp2; 
            if( a[i] == '/') tmp3 = tmp1 / tmp2; 
            c.push(tmp3);
        }
        else c.push(a[i]-'0');
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
        cout<<calcu(a)<<endl;
    }
    
    return 0;
}