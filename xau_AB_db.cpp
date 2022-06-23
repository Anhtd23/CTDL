#include<bits/stdc++.h>
using namespace std;
int n, k;
int countA = 0;
int a[20];
string store[1000];
void print(){
    string tmp = "";
    for(int i = 0; i < n ; i++){
        if(a[i] == 1) tmp += "A";
        else tmp += "B";
    }
    store[countA] = tmp;
    countA++;
}
bool check(){
    int count = 0;
    for(int i = 0; i < n ; i++){
        if(a[i] == 1){
            int j = 0;
            while (a[i] == 1) {j++;i++;};
            if(j > k ) return false;
            else if(j == k) count++;
        }
    }
    if(count == 1 ) return true;
    else return false;
}
void Try(int i){
    for(int  j = 1; j >= 0 ; j--){
        a[i] = j;
        if(i == n-1 ) 
            {if(check()) print();}
        else Try(i+1);
    }
}
int main(){
        cin>>n>>k;
        Try(0);
        cout<<countA<<endl;
        for(int i = 0; i < countA; i++) cout<<store[i]<<endl;
    return 0;
}