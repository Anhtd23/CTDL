#include<bits/stdc++.h>
using namespace std;
string s[11];
int store[11][150]={0};
int n;
int demTrung(int a[],int nA, string b, int nB){
    int countA = 0;
    for(int i = 0 ; i < nB; i++){
        if(a[b[i]] == 1){
            countA++;
        }
    }    
    return countA;
}
int check(int a[]){
    int countA = 0;
    for(int i = 0 ; i < n - 1; i++){
        countA += demTrung(store[a[i]], s[a[i]].length(), s[a[i+1]], s[a[i+1]].length());
    }
    return countA;
}
int minTrung(){
    int ans = 100000;
    int a[n];
    for(int i = 0 ; i < n ; i++) a[i] = i;
    do
    {
        ans = min(check(a), ans);
    }while (next_permutation(a, a+n));
    return ans;
}
int main(){
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>s[i];
        for(int i = 0 ; i < n ; i++){
            int len = s[i].length();
            for(int j = 0 ; j < len ; j++){
                store[i][s[i][j]] = 1;
            }
        }
        cout<<minTrung()<<endl;        
    

    return 0;
}