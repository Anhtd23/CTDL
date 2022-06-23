#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
long long point[1000][1000];
int m, n;
long long minRoad(){
    for(int i = 1 ; i <= n ; i++) point[1][i] = point[1][i-1] + a[1][i];
    for(int i = 2 ; i <= m ; i++) point[i][1] = point[i-1][1] + a[i][1];
    
    for(int i = 2 ; i <= m ; i++){
        for(int j = 2 ; j <= n ; j++){
            point[i][j] = min(point[i-1][j],min( point[i-1][j-1], point[i][j-1])) + a[i][j];
        }
    }
    return point[m][n];
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
        cout<<minRoad()<<endl;
    }
    

    return 0;
}