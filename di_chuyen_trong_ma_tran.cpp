#include<iostream>
using namespace std;
int a[120][120] = {0};
int D[120][120] = {0};
int m, n;
void init(){
    for(int i = 0; i < 120; i++){
        D[0][i] = 1;
        D[i][i] = 1;
    }
    for(int i = 0 ; i < 120 ; i++) D[1][i] = i;
}
int C(int x, int n){
    if( D[x][n]) return D[x][n];
    else return C(x, n-1) + C(x-1, n -1);
}
int findWay(){
    return C(m-1, n + m -2);
}
int main(){
    int t;
    cin>>t;
    init();
    while (t--)
    {
        cin>>m>>n;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++) cin>>a[i][j];
            
        }
        cout<<findWay()<<endl;
    }
    

    return 0;
}