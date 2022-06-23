#include<bits/stdc++.h>
using namespace std;
typedef pair<char, int> CI;
void dauNgoac(string a){
    stack<CI> c;
    int n = a.length();
    int level = 1;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == '('){
            cout<<level<<" ";
            c.push(CI('(', level));
            level++;
        }
        else if(a[i] == ')') {
            CI k = c.top();
            c.pop();
            cout<<k.second<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    cin.ignore(1);
    while (t--)
    {
        string a;
        getline(cin, a);
        dauNgoac(a);
    }
    return 0;
}