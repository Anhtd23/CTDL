#include<bits/stdc++.h>
using namespace std;
int D[1001];
int a[1001][1001];
typedef pair<int, int> II;
int V, E;
bool check(){
    D[1] = 0;
    for(int i = 2 ; i <= V; i++){
        if(a[1][i] != 1e9 ) D[i] = a[1][i];
        else D[i] = 1e9;
    }
    for(int i = 1 ; i <= V - 2;  i++){
        for(int j = 1 ; j <= V ; j++){
            for(int k = 1 ; k <= V ;  k++){
                if(a[k][j] != 1e9 &&  D[j] > D[k] + a[k][j]) D[j] = a[k][j] + D[k];
            }
        }
    }
    for(int j = 1; j <= V ; j++){
        for(int k = 2 ; k <= V ; k++){
            if(a[k][j] != 1e9 && D[j] > D[k] + a[k][j]) return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E;
        for(int i = 1 ; i <= V; i++){
            for(int j = 1 ; j <= V; j++) {
                if(i == j) a[i][j] = 0;
                a[i][j] = 1e9;
            }
        }
        int tmp1, tmp2, tmp3;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2>>tmp3;
            a[tmp1][tmp2] = tmp3;
        }
        cout<<check()<<endl;
    }
    
    return 0;
}