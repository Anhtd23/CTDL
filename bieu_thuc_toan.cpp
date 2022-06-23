#include<bits/stdc++.h>
using namespace std;
int X[4];
bool check = 0;
int a[5];
int b[5];
int tinh(){
    int sum = a[b[0]];
    for(int i = 0 ; i < 4 ; i++){
        if(i == 0) {
            if(X[i] == 0) sum += a[b[1]];
            else if(X[i] == 1) sum -= a[b[1]];
            else sum *= a[b[1]];
        }
        else if(i == 1) {
            if(X[i] == 0) sum += a[b[2]];
            else if(X[i] == 1) sum -= a[b[2]];
            else sum *= a[b[2]];
        }
        else if(i == 2){
            if(X[i] == 0) sum += a[b[3]];
            else if(X[i] == 1) sum -= a[b[3]];
            else sum *= a[b[3]];
        }
        else {
            if(X[i] == 0) sum += a[b[4]];
            else if(X[i] == 1) sum -= a[b[4]];
            else sum *= a[b[4]];
        }
    }
    return sum;
}
bool checkA(){
    for(int i = 0 ; i  < 5 ; i++) b[i] = i;
    if(tinh() == 23) return true;
    while (next_permutation(b, b+4))
    {
        if(tinh() == 23) return true;
    }
    return false;

}
void Try(int i){
    for(int j = 0 ; j < 3 ; j++){
        X[i] = j;
        if(i == 3) {  
            if(checkA()){
                check = 1;
            }
        }
        else Try(i+1);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        for(int i = 0 ; i < 5; i++) {
            cin>>a[i];
        }
        check = 0;
        Try(0);
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    

    return 0;
}