#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int maxLen(string b){
    int len = b.length();
    for(int i = 1 ; i <= len ; i++){
        for(int j = 1 ; j <= len ; j++){
                if(b[i-1] == b[j-1] && i != j) a[i][j] = a[i-1][j-1] + 1;
                else a[i][j] = max(a[i-1][j], a[i][j-1]);
        }
    }
    return a[len][len];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;cin>>n;
        string b;
        cin>>b;
        cout<<maxLen(b)<<endl;
    }
    return 0;
}