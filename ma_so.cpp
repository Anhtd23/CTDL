#include<bits/stdc++.h>
using namespace std;
string storeA[10000];
int countA = 0, n;

void Try(string b, int i, string a){
    if(i == n ){
        storeA[countA++] = b;
        return;
    }
    for(int j = 0 ; j < n  ; j++){
        Try(b+a[j], i+1, a);
    }
}
void in(string a, string b){
    Try("", 0, b);
    do{
        for(int i = 0 ; i < countA; i++){
            cout<<a+storeA[i]<<endl;
        }
    }while (next_permutation(a.begin(), a.end()));
    
    
}
int main(){
    cin>>n;
    string a, b;
    for(int i = 'A'; i < n + 'A'; i++) a += i;
    for(int i = '1'; i < n + '1'; i++) b += i;
    in(a, b);
    return 0;
}