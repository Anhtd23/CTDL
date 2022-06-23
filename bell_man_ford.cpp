#include<bits/stdc++.h>
using namespace std;
class Dothi{
    int a[100][100];
    int truoc[100];
    int D[100];
    int V, u;
    public:
    void nhap(){
        cin>>V>>u;
        for(int i = 1 ; i <= V ;i++){
            for(int j = 1 ; j <=  V ; j++){
                cin>>a[i][j];
            }
        }
    }
    void inDuong(int v){
        while (true)
        {
            cout<<v<<" <- ";
            v = truoc[v];
            if(v == u) {
                cout<<u;
                break;
            }
        }
        cout<<endl;
    }
    void bellManFord(){
        for(int i = 1 ; i <= V ; i++) D[i] = 1e9;
        D[u] = 0;
        truoc[u] = u;
        for(int i = 1 ; i <= V ; i++){
            if(i != u){
                if(a[u][i] != 0 ) {
                    D[i] = a[u][i];
                    truoc[i] = u;
                }
            }
        }
        for(int k = 1 ; k <= V - 2 ; k++){
            for(int i = 1 ; i <= V; i++){
                if(i != u){
                    for(int j = 1 ; j <= V ; j++){
                        if(a[j][i] !=  0 && D[i] > D[j] + a[j][i] ){
                            D[i] = D[j] + a[j][i];
                            truoc[i] = j;
                        }
                    }
                }
            }
        }
        for(int i = 1 ; i <= V; i++){
            cout<< "K/c "<<u<<" -> "<<i<<" = ";
            if(D[i] != 1e9){
                cout<<D[i]<<";   ";
                inDuong(i);
            }
            else cout<<"INF;"<<endl;
        }
    }
};
int main(){
    Dothi a;
    a.nhap();
    a.bellManFord();
    return 0;
}