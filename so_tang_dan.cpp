#include<bits/stdc++.h>
using namespace std;
long long p = 1e9 + 7;
long long store[110][10];
void make(){
    for(int k = 1 ; k <= 110 ; k++){
        for(int i = 1 ; i < 10 ; i++){
            long long sum = 0;
            for(int j = i ; j >= 1; j--){
                sum = sum + store[k-1][j];
            }
            store[k][i] = sum;
        }
    }
}
long long numInc(int n){
    long long sum = 0;
    for(int i = n ; i >= 0 ; i--){
        sum = (sum + store[i][9])%p;
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    for(int i = 1 ; i < 10 ; i++) store[0][i] = 1;
    make();
    while (t--)
    {
        int n;
        cin>>n;
        cout<<numInc(n)<<endl;
    }
    return 0;
}