#include<bits/stdc++.h>
using namespace std;
int a[20];
int n, k ,s;
int countA= 0;
void Try(int i, int run, int sum){
    if(sum == s){
        if(k == i ) countA++;
    }
    else if(sum < s){
        for(int j = run ; j <= n ; j++){
            int tmp = sum + j;
            if(tmp <= s) Try(i+1, j+1, tmp);
            else break;
        }
    }
}
int main(){
    while (true)
    {
        countA = 0;
        cin>>n>>k>>s;
        if( n == 0 && k == 0 && s == 0) break;
        Try(0, 1, 0);
        cout<<countA<<endl;
    }
    
    return 0;    
}