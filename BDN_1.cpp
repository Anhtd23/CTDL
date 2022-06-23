#include<bits/stdc++.h>
using namespace std;
int compareStr(string a, string b){
    int n1 = a.length();
    int n2 = b.length();
    if(n1 != n2) return n1 - n2;
    else{
        for(int i = 0 ; i < n1 ; i++){
            if(a[i] != b[i]) return a[i] - b[i];
        }
    }
    return 1000;
}
long long cal(string a){
    int n = a.length();
    long long m = 0;
    for(int i = 0 ; i < n ; i++) m += (((long long)pow(2, n - i - 1)) * (a[i] - '0'));
    return m;
}
long long BDN(string a){
    queue<string> q;
    q.push("1");
    if(compareStr("1", a) > 0) return 1;
    while (true)
    {
        string tmp = q.front();
        string tmp1 = tmp + "0";
        q.push(tmp1);
        int b = compareStr(tmp1, a);
        if(b > 0){
            if(b > 0 && b != 1000) return cal(tmp1) - 1;
            if( b == 1000) return cal(tmp1);
        }
        string tmp2 = tmp + "1";
        q.push(tmp2);
        b = compareStr(tmp2, a);
        if(b > 0){
            if(b > 0 && b != 1000) return cal(tmp2) - 1;
            if( b == 1000) return cal(tmp2);
        }
        q.pop();
    }
    
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        cout<<BDN(a)<<endl;
    }
    

    return 0;
}