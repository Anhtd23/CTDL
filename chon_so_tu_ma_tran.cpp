#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int D[100];
string store[100];
int countA = 0;
void print(int n){
    string tmp = "";
    for(int i = 1; i <= n ; i++){
        tmp += (D[i]+'0');
        tmp += " ";
    }
    store[countA] = tmp;
    countA++;
}
bool tinh(int n , int k){
    int sum = 0;
    for(int i = 1; i <= n; i++ ){
        sum += a[i-1][D[i]-1];
    }
    if(sum == k) return true;
    else return false;
}

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 0; i  < n ; i++) {
        for(int j =  0; j < n ; j++) cin>>a[i][j];
    }
    for(int i = 1 ; i <= n ; i++) D[i] = i;

    do {
        if(tinh(n, k)) print(n);
    }while(next_permutation(D+1, D+n+1));
    cout<<countA<<endl;
    for(int i = 0; i < countA; i++) cout<<store[i]<<endl;
    return 0;
}