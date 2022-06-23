#include<bits/stdc++.h>
using namespace std;
class Dothi{
    public:
    int n, v;
    int a[100][100];
    int G[100];
    bool chuaxet[100];
    void nhap(){
        cin>>n>>v;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cin>>a[i][j];
            }
        }
    }
    void reset(){
        for(int i = 1; i <= n ; i++) chuaxet[i] = false;
    }
    void in(){
        for(int i = 1 ; i <= n ; i++) cout<<G[i]<<" ";
        cout<<G[1]<<endl;
    }
    void haminton(int k){
        for(int i = 1 ; i <= n ; i++){
            if(a[G[k-1]][i] == 1 ){
                if(k == n + 1 && i == 1 ){
                    in();
                }
                else if(!chuaxet[i]){
                    G[k] = i;
                    chuaxet[i] = true;
                    haminton(k+1);
                    chuaxet[i] = false;
                }
            }
        }
    }
    void cycle_haminton(){
        reset();
        G[1] = v;
        chuaxet[v] = true;
        haminton(2);
    }
};
int main(){
    Dothi a;
    a.nhap();
    a.cycle_haminton();
}