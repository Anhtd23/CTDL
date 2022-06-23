#include<bits/stdc++.h>
using namespace std;
int maxSub(string a, string b){
    int nA = a.length();
    int nB = b.length();
    int F[nA+1][nB+1] = {0};
    for(int i = 0 ; i <= nA; i++) F[i][0] = 0;
    for(int i = 0 ; i <= nB; i++) F[0][i] = 0;
    for(int i = 1 ; i <= nA; i++){
        for(int j = 1 ; j <= nB ; j++){
            if(a[i-1] == b[j-1]) F[i][j] = F[i-1][j-1] + 1;
            else F[i][j] = max(F[i-1][j], F[i][j-1]);
        }
    }
    return F[nA][nB];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a, b;
        cin>>a>>b;
        cout<<maxSub(a, b)<<endl;
    }
    
    return 0;
}