#include<bits/stdc++.h>
using namespace std;
int mark[101][101][101];
int maxSeq(string a, string b, string c){
    int n1 = a.length();
    int n2 = b.length();
    int n3 = c.length();
    for(int i = 1 ; i <= n1; i++ ){
        for(int j = 1; j <= n2; j++){
            for(int k = 1; k <= n3; k++){
                int tmp = max(mark[i-1][j][k], max(mark[i][j-1][k], mark[i][j][k-1]));
                mark[i][j][k] = tmp;
                if(a[i-1] == b[j-1] && c[k-1] == a[i - 1]) mark[i][j][k] = mark[i-1][j-1][k-1] + 1;
            }
        }
    }
    return mark[n1][n2][n3];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int x, y, z;
        cin>>x>>y>>z;
        string a, b, c;
        cin>>a>>b>>c;
        cout<<maxSeq(a, b, c)<<endl;
    }
    return 0;
}