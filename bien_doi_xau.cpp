#include<bits/stdc++.h>
using namespace std;
int mark[102][102];
int countChange(string a, string b){
    int len1 = a.length(), len2 = b.length();
    for(int i = 1 ; i <= len1; i++){
        for(int j = 1 ; j <= len2; j++){
            if(a[i-1] == b[j-1]) mark[i][j] =  mark[i-1][j-1];
            else mark[i][j] = 1 + min(mark[i-1][j], min(mark[i-1][j-1], mark[i][j-1]));
        }
    }
    /*for(int i = 0 ; i <= len1 ; i++){
        for(int j = 0 ; j <= len2 ; j++) cout<<mark[i][j]<<" ";
        cout<<endl;
    }*/
    return mark[len1][len2];
}
int main(){
    int t;
    cin>>t;
    for(int i = 1 ; i < 102; i++) mark[0][i] = i;
    for(int i = 1 ; i < 102; i++) mark[i][0] = i;
    while (t--)
    {
        string a, b;
        cin>>a>>b;
        cout<<countChange(a, b)<<endl;
    }
    

    return 0;
}