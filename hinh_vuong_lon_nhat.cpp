#include<bits/stdc++.h>
using namespace std;
int a[600][601];
int n, m;
int maxSquare(){
    int vertical[m+1][n+1];
    int hoz[m+1][n+1];
    for(int i = 1 ; i <= n ; i++) vertical[0][i] = 0;
    for(int i = 1 ; i <= m ; i++) hoz[i][0] = 0;
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(a[i][j] != 0 ) hoz[i][j] = hoz[i][j-1] + 1;
            else hoz[i][j] = 0;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(a[j][i] != 0 ) vertical[j][i] = vertical[j-1][i] + 1;
            else vertical[j][i] = 0;
        }
    }
    /*
    
    for(int i = 1 ; i <= m; i++){
        for(int j = 1; j <= n ; j++) cout<<hoz[i][j]<<" ";
        cout<<endl;
    }
    for(int i = 1 ; i <= m; i++){
        for(int j = 1; j <= n ; j++) cout<<vertical[i][j]<<" ";
        cout<<endl;
    }*/
    int maxA = 0;
    for(int i = m; i > 0 ; i--){
        for(int j = n; j > 0 ; j--){
            if(a[i][j] == 1){
                int k = j;
                int h = i;
                int count = 1;
                while (vertical[i][k] >= count && hoz[h][j] >= count)
                {
                    if(maxA < count ) maxA = count;
                    count++;
                    k--;h--;
                }
            }
        }
    }
    return maxA;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>m>>n;
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++) cin>>a[i][j];
        }
        cout<<maxSquare()<<endl;
    }
    
    return 0;
}