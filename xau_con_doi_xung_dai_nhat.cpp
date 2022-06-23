#include<bits/stdc++.h>
using namespace std;
bool mark[1000][1000];
int maxA = 1;
bool check(int x1, int x2){
    for(int i = 0 ; i <= x2 - x1 ; i++){
        if(mark[x2-i][x1+i] == false) return false;
    }
    return true;
}
void maxSymmetry(string a){
    int n = a.length();
    if( n == 1 ){
        maxA = 1;
        return;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n; j++){
            mark[i][j] = false;
            if(a[i] == a[j]) mark[i][j] = true;
        }
    }
    for(int i = 0 ; i < n - 1; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(mark[i][j] == 1 && j - i + 1 > maxA){
                if(check(i, j)) {
                    if(maxA < j - i + 1) maxA = j - i + 1; 
                }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        maxA = 1;
        maxSymmetry(a);
        cout<<maxA<<endl;
    }
    
    return 0;
}