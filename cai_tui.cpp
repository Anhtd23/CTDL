#include<bits/stdc++.h>
using namespace std;
int n, V;

int maxValue(int a[], int value[]){
    int D[n+1][V+1] = {0};
    for(int i = 0 ; i <= V ; i++) D[0][i] = 0;
    for(int i = 0 ; i <= n; i++) D[i][0] = 0;
    for(int i = 1 ; i  <= n ; i++){
        for(int j = 1 ; j <= V ; j++){
            D[i][j] = D[i][j-1];
            if( j - a[i-1] >= 0 && value[i-1] + D[i-1][j-a[i-1]] > D[i][j]) D[i][j] = value[i-1] + D[i-1][j-a[i-1]];
            D[i][j] = max(D[i][j], D[i-1][j]);
        }
    }
    /*for(int i = 0 ; i <= n ; i++){
        for(int j = 0; j <= V; j++) cout<<D[i][j]<<" ";
        cout<<endl;
    }*/
        
    return D[n][V];
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>V;
        int a[n];
        int value[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        for(int i = 0 ; i < n ; i++) cin>>value[i];
        cout<<maxValue(a, value)<<endl;

    }
    

    return 0;
}