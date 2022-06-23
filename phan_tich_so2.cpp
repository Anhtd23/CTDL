#include<bits/stdc++.h>
using namespace std;
int m, countA;
string s[100000];
void in(string a){
    string  tmp = "(";a.pop_back();
    tmp+= a;tmp+= ")";
    s[countA++] = tmp;
}
string chuyen(int n){
    stringstream ss;
    ss<<n;
    string tmp;
    ss>>tmp;
    return tmp;
}
void gene(int n ,int sum, string a){
    if(sum > m) return;
    if(sum == m) {
        in(a);
        return;
    }
    for(int i = n ; i >= 1 ; i--){
        string c = chuyen(i);
        gene(i, sum + i, a + c + " ");
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>m;
        countA = 0;
        gene(m,0,"");
        cout<<countA<<endl;
        for(int i=0; i < countA; i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}