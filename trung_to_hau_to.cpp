#include<bits/stdc++.h>
using namespace std;
string a;

bool isOperatorChar(char a){
    if( a == '+' || a =='-' || a == '*' || a== '/' || a == '%') return true;
    else return false;
}

pair<string, int> midToBack( int begin){
    stack<string> c;
    int i;
    pair<string,int> res;
    for(i = begin ; a[i] != ')' && i < a.length(); i++){
        if(a[i] == '('){
            res = midToBack( i +1);
            c.push(res.first);
            i = res.second;
        }
        else if(isOperatorChar(a[i])){
            string tmp1 = c.top();
            c.pop();
            string tmp2 = "";
            tmp2 += a[i];
            if(a[i+1] == '('){
                res = midToBack( i+1);
                c.push(tmp1 + res.first + tmp2);
                i = res.second;
            }
            else{
                string tmp3 = "";
                tmp3 += a[i+1];
                c.push(tmp1+tmp3+tmp2);
                i++;
            }
        }
        else {
            string tmp = "";
            tmp += a[i];
            c.push(tmp);
        }
    }
    res.first  = c.top();
    res.second = i;
    return res;
}
int main(){ 
    int t;
    cin>>t;
    while (t--)
    {
        cin>>a;
        cout<<midToBack(0).first<<endl;
    }
    
    return 0;
}