#include<bits/stdc++.h>
using namespace std;
bool div0(string a, int n){
    int div = 0;
    int len = a.length();
    for(int i = 0 ; i < len; i++){
        int tmp = div*10 + (a[i]-'0');
        div = tmp % n;
    }
    if(div == 0) return true;
    else return false;
}
string divN(int n){
        queue<string> q;
        q.push("9");
        string a = "9";
        if(div0(a, n )) return a;
        while (true)
        {
            string tmp = q.front();
            string tmp1 = tmp + "0";
            q.push(tmp1);
            if(div0(tmp1, n)) return tmp1;
            string tmp2 = tmp + "9";
            q.push(tmp2);
            if(div0(tmp2, n)) return tmp2;
            q.pop();
        }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<divN(n)<<endl;
    }
    return 0;
}