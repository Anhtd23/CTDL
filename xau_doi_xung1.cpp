#include<bits/stdc++.h>
using namespace std;
int mark[50][50];
int minIns(string a){
    int n = a.length();
    mark[0][0] = 0;
    for(int i = 0 ; i <n ; i++){
        for(int j = 0 ; j < n ; j++) mark[i][j] = 0;
    }
    for(int i = 0 ; i < 50; i++ ) mark[i][i] = 1;
    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = i + 1 ; j < n ; j++){
            if(a[i] == a[j]){
                if(j == i + 1){
                    mark[i][j] = 2;
                }
                else{
                    mark[i][j] = mark[i+1][j-1] + 2;
                }
            }
            else{
                if(j == i + 1) mark[i][j] = 1;
                else{
                    mark[i][j] = max(mark[i+1][j], mark[i][j-1]);
                }
            }
        }
    }
    return a.length() - mark[0][n-1];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        cout<<minIns(a)<<endl;
    }
    

    return 0;
}