#include<bits/stdc++.h>
using namespace std;
bool isOperatorChar(char a){
    if( a == '+' || a =='-') return true;
    else return false;
}
void doi(bool &check){
    if(check) check = false;
    else check = true;
}
string equivalen(string a){
    string ans = "";
    int len = a.length();
    stack<pair<char, int>> c;
    bool check = true;
    pair<char, int> tmp;
    tmp.second = 0;
    for(int i = 0 ; i < len ; i++){
        if(a[i] == '('){
            tmp.first = '(';
            if(i == 0){
                c.push(tmp);
                continue;
            }
            if(a[i-1] == '-') {
                tmp.second = -1;
                doi(check);
                }
                else tmp.second = 1;
            c.push(tmp);
        }
        else if(a[i] == ')'){
            tmp = c.top();
            c.pop();
            if(tmp.second == -1) doi(check);
        }
        else if(isOperatorChar(a[i])){
            if(a[i+1] != '('){
                if(check) ans += a[i];
                else {
                    if(a[i] == '-') ans+= "+";
                    else ans += "-";
                }
            }
        }
        else {
            if(a[i-1] != '('){
                ans += a[i];
            }
            else {
                if(check){
                    ans += "+";
                }
                else ans += "-";
                ans += a[i];
            }
        }
    }
    if( ans[0] == '+') ans.erase(0, 1);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a, b;
        cin>>a>>b;
        string makeA = equivalen(a);
        string makeB = equivalen(b);
        if(makeA.compare(makeB) == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    

    return 0;
}