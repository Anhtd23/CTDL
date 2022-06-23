#include<bits/stdc++.h>
using namespace std;
bool isOperator(char a){
    if( a =='+' || a =='-' || a == '*' || a== '/' || a == '%' || a == '^') return true;
    else return false;
}
bool isOperatorString(string a){
    if( a =="+" || a =="-" || a == "*" || a== "/" || a == "%" || a == "^") return true;
    else return false;
}
string toString(char a){
    string tmp = "";
    tmp += a;
    return tmp;
}

string posToPre(string a){
    int len = a.length();
    stack<string> c;
    /*for(int i = len - 1 ; i >= 0 ; i--){
        if(isOperator(a[i])){
            c.push(toString(a[i]));
        }
        else{
            if(c.size() < 2) c.push(toString(a[i]));
            else {
                string tmp1 = c.top();
                c.pop();
                string tmp2 = c.top();
                c.push(tmp1);
                if(!isOperatorString(tmp1) && isOperatorString(tmp2) ){
                    while (true) 
                    {
                        string tmp3 = tmp2 + toString(a[i]) + tmp1;
                        c.push(tmp3);
                        if(c.size() == 1) break;
                        tmp1 = c.top();c.pop();
                        tmp2 = c.top();c.pop();
                        tmp3 = c.top();
                        if(isOperatorString(tmp1) || isOperatorString(tmp2) || !isOperatorString(tmp1)){
                            c.push(tmp2);
                            c.push(tmp1);
                            break;
                        }
                    }
                    
                }
                else{
                    c.push(toString(a[i]));
                }
            }
            
        }
    }
    while (c.size() != 1)
    {
        string tmp1 = c.top();
        c.pop();
        string tmp2 = c.top();
        c.pop();
        string tmp3 = c.top();
        c.pop();
        c.push(tmp3 + tmp1 + tmp2);
    }*/
    for(int i = 0 ; i < len; i++){
        if(isOperator(a[i])){
            string tmp1 = c.top();c.pop();
            string tmp2 = c.top();c.pop();
            string tmp3 = toString(a[i]) + tmp2 + tmp1;
            c.push(tmp3);
        }
        else{
            c.push(toString(a[i]));
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
        cout<<posToPre(a)<<endl;
    }
    return 0;
}