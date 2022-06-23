#include<bits/stdc++.h>
using namespace std;
char toChar(int n){
    return (char)('A'- 1 + n);
}
int way(string a){
    int n = a.length();
    if(a[0] == '0') return 0;
    int b[n];
    for(int i = 0 ; i < n ; i++) b[i] = a[i]-'0';
    int F[n+1];
    F[0] = 1;
    F[1] = 1;
    for(int i = 2; i <= n ; i++){
        if(b[i-1] != 0){
            int tmp = 0;
            if(b[i-1] + b[i-2] * 10 <= 26 && b[i-2] != 0) tmp = F[i-2];
            tmp += F[i-1];
            F[i] = tmp;
        }
        else{
            if(b[i-2] == 1 || b[i-2] == 2) F[i] = F[i-2];
            else return 0;
        }
    }
    /*for(int i = 0 ; i <= n  ; i++) cout<<F[i]<<" ";
    cout<<endl;*/
    return F[n];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        cout<<way(a)<<endl;
    }
    return 0;
}