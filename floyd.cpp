#include<bits/stdc++.h>
using namespace std;
int V, E;
#define Inf  1e6;
int D[200][200];
int main(){
    cin>>V>>E;
    int tmp1, tmp2, tmp3;
    for(int i = 1  ; i <= V; i++){
        for(int j = 1 ; j <= V; j++){
            if(i == j) D[i][j] = 0;
            else D[i][j] = Inf;
        }
    }
    for(int i = 0 ; i < E; i++){
        cin>>tmp1>>tmp2>>tmp3;
        D[tmp1][tmp2] = tmp3;
        D[tmp2][tmp1] = tmp3;
    }
    for(int k = 1 ; k <= V; k++){
        for(int i = 1 ; i <= V ; i++){
            for(int j = 1 ; j <= V ; j++){
                if(D[i][j] > D[i][k] + D[k][j] && (D[i][k] != 1e9 && D[k][j] != 1e9)) D[i][j] = D[i][k] + D[k][j];
            }
        }
    }
    int Q;
    cin>>Q;
    for(int i = 0 ; i < Q; i++){
        cin>>tmp1>>tmp2;
        cout<<D[tmp1][tmp2]<<endl;
    }
    return 0;
}