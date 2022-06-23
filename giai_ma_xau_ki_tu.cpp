#include<bits/stdc++.h>
using namespace std;
typedef pair<string, int> II;
string nhanXau(string a, int n){
    string c = a;
    for(int i = 1 ; i < n ; i++){
        c += a;
    }
    return c;
}
void giaiMa(string a){
    int n = a.length();
    stack<II> c;
    int carry = 0;
    string tmp = "";
    c.push(II("", 0));
    for(int i = 0 ; i < n ; i++){
        //if(!c.empty()) cout<<c.top().first<<endl;
        if(a[i] >= '0' && a[i] <= '9') {
            carry = (a[i] - '0') + carry * 10;
        }
        else if(a[i] == '['){
            if(carry == 0 ) carry = 1;
            c.push(II("[", carry));
            c.push(II("", 0));
            carry = 0;
        }
        else if(a[i] == ']'){
            II tmp1 = c.top();c.pop();
            II tmp2 = c.top();c.pop();
            string k = nhanXau(tmp1.first, tmp2.second);
            string tmp3 = c.top().first + k;
            c.pop();
            c.push(II(tmp3, 0));
        }
        else {
            string k = c.top().first;c.pop();
            k+= a[i];
            c.push(II(k, 0));
        }
    }
    cout<<c.top().first<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        giaiMa(a);
    }
    return 0;
}