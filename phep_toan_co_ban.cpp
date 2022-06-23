#include<bits/stdc++.h>
using namespace std;
int n;
string a;
bool checkA = false;
char op[4] = {'+', '-', '*', '/'};
bool check(string c){
    //cout<<c<<endl;
    stringstream ss(c);
    int a, d , e;
    char b, tmp;
    ss>>a;
    ss>>b;
    ss>>d;
    ss>>tmp;
    ss>>e;
    if(b == '+'){
        if(a + d == e) return true;
    }
    else if(b == '-'){
        if(a - d == e) return true;
    }
    else if( b == '*'){
        if(a * d == e) return true;
    }
    else {
        if(a / d == e && a % d == 0) return true;
    }
    return false;
}
void coBanVai(string c,int i){
    if(checkA == true) return;
    if(i == n ){
        if(check(c)) {
            cout<<c<<" ";
            checkA = true;
        }
        return;
    } 
    if(c[i] == '?'){
        if(i == 3) {
            for(int j = 0 ; j < 4 ; j++){
                c[i] = op[j];
                coBanVai(c, i+1);
            }
        }
        else{
            if(i == 1 || i == 6 || i == 11){
                c[i] = '0';
                coBanVai(c, i+1);
            }
            for(char j = '1' ; j <= '9'; j++){
                c[i] = j;
                coBanVai(c, i+1);
            }
            
        }
    }
    else coBanVai(c, i+1);
    
}
int main(){
    int t;
    cin>>t;
    cin.ignore(1);
    while (t--)
    {
        checkA = false;
        string a;
        getline(cin, a);
        n = a.length();
        coBanVai(a, 0);
        if(checkA == false) cout<<"WRONG PROBLEM!";
        cout<<endl;
    }
    

    return 0;
}