#include<bits/stdc++.h>
using namespace std;
bool isOperator(char a){
    if( a == '+' || a =='-' || a == '*' || a== '/' || a == '%') return true;
    else return false;
}
typedef pair<string, int> loot;
string inToBack(string a){
    stack<pair<string, int>> c;
    int level = 0;
    for(int i = 0 ; i < a.length(); i++){
        if(a[i] == '(') level++;
        else if(a[i] == ')') level--;
        else if(isOperator(a[i])){
            string tmp = "";
            tmp += a[i];
            loot tmp1;
            tmp1.first = tmp;
            tmp1.second = level;
            c.push(tmp1);
        }
        else{
            if(isOperator(a[i-1])){
                loot tmp1 = c.top();c.pop();
                loot tmp2 = c.top();c.pop();
                string tmp3 ; tmp3 = "";
                tmp3 += a[i];
                loot tmp4;
                tmp4.first = tmp2.first + tmp3+ tmp1.first;
                tmp4.second = level;
                c.push(tmp4);
            }
            else{
                string tmp = "";
                tmp += a[i];
                loot tmp1;
                tmp1.first = tmp;
                tmp1.second = level;
                c.push(tmp1);
            }
        }
    }
    loot b[20];
    int i = 0;
    while (!c.empty())
    {
        b[i++] = c.top();c.pop();
    }
    for(int j = 0 ; j < i; j++){
        cout<<b[j].first<<" "<<b[j].second<<endl;
    }
    return "1";
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        cout<<inToBack(a)<<endl;
    }
    

    return 0;
}