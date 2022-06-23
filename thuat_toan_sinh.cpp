#include<bits/stdc++.h>
using namespace std;

void print(int n, string a, int check){
        for(int i =  0; i < a.length(); i++) cout<<a[i]<<" ";
        if(n % 2 == 1) cout<<check<<" ";
        for(int i = a.length() - 1 ; i>= 0 ; i--) cout<<a[i]<<" ";
        cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int k = n /2;
    string a = "";
    for(int i = 0 ; i < k; i++) a += "0";
    print(n, a, 0);
    int i = k - 1;
    while(i >= 0){
        for(i = k - 1; a[i] == '1' && i >= 0; i--){
            a[i] = '0';
        }
        if( i >= 0 ) {
            a[i] = '1';
            print(n, a, 0);
            if( n % 2 == 1)
            print(n, a, 1);
        }
    }
    return 0;
}