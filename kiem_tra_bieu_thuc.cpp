#include<bits/stdc++.h>
using namespace std;
bool dau(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/') return true;
    else return false;
}
bool chu(char a){
    return (a>= 'a' && a <= 'z' ) || a == '1' || (a <= 'Z' && a >= 'A') || (a <= '9' && a >= '0'); 
}
bool check(string a){
    if(a[0] != '(') {
        a = "(" + a;
        a += ')';
    }
    stack<char> c;
    int n = a.length();
    bool in = false;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == ' ') continue;
        if(c.empty()){
            if(dau(a[i]) || a[i] == ')') return false;
            else c.push(a[i]);
        }
        else if( a[i] == '('){
            if(c.empty()) c.push(a[i]);
            else if (chu(c.top())) return false;
            else c.push('(');
        }
        else if(chu(a[i])){
            if(chu(c.top())) return false;
            c.push(a[i]);
        }
        else if(dau(a[i])){
            if(chu(c.top())) c.push(a[i]);
            else return false;
        }
        else {
            if(chu(c.top())){
                int count = 0;
                while(!c.empty() && c.top() != '(' ){
                    c.pop();
                    count++;
                }
                if(count == 1) return false;
                c.pop();
                if(!c.empty()) c.push('1'); 
            }
        }
    }
    if(c.empty()) return true;
    else return false;
}
int main(){
    int t;
    cin>>t;
    cin.ignore(1);
    while (t--)
    {
        string a;
        getline(cin, a);
        if(!check(a)) cout<<"Yes";
        else cout<<"No";
        cout<<endl;        
    }
    

    return 0;
}