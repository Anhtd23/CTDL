#include<bits/stdc++.h>
using namespace std;
string xauTruoc(string a){
    int n = a.length();
    int i = n - 1;
    while (i >= 0 && a[i] == '0'){
        a[i] = '1';
        i--;
    }
    if(i < 0 ) return a;
    else{
        a[i] = '0';
        return a;
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        cout<<xauTruoc(a)<<endl;
    }
    

    return 0;
}