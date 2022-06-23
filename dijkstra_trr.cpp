#include<bits/stdc++.h>
using namespace std;
class Dothi{
    int a[100][100];
    int V, start = 0;
    int D[100], truoc[100];
    bool chuaxet[100];
    public:
    void nhap(){
        cin>>V>>start;
        for(int i = 1 ; i <= V ; i++){
            for(int j = 1 ; j <= V ; j++) {
                cin>>a[i][j];
            }
        }
        for(int i = 1 ; i <= V; i++) {
            D[i] = 1000000;
            chuaxet[i] = false;
            truoc[i] = 0;
        }   
        D[0] = 10000001;
        for(int i = 1 ; i <= V; i++){
            if(a[start][i] != 0 ) {
                D[i] = a[start][i];
                truoc[i] = start;
            }
        }
        D[start] = 0;
        chuaxet[start] = true;
        truoc[start] = start;
    }
    bool check(){
        for(int i = 0 ; i <= V; i++){
            if(!chuaxet[i]) return false;
        }
        return true;
    }
    void inDuongDi(int v){
        while(true){
            cout<<v<<" <- ";
            v = truoc[v];
            if(v == start) {
                break;
            }
            
        }
        cout<<start<<endl;
    }
    void dijkstra(){
        while(!check()){
            int canhMin = 0;
            for(int i = 1 ; i <= V ; i++){
                if(D[i] < D[canhMin] && !chuaxet[i]){
                    canhMin = i;
                }
            }
            cout<<canhMin<<endl;
            chuaxet[canhMin] = true;
            for(int i = 1  ;  i <= V; i++){
                if(a[canhMin][i]  > 0 ){
                    if(D[canhMin] + a[canhMin][i] < D[i]){
                        D[i] = D[canhMin] + a[canhMin][i];
                        truoc[i] = canhMin;
                    }
                }
            }
        }
        for(int i = 1 ; i <= V; i++){
            cout<<"K/c "<<start<<"<-"<<i<<" = ";
            if(D[i] == 1000000) cout<<"INF;"<<endl;
            else {
                cout<<D[i]<<"   ";
                inDuongDi(i);
            }
        }
    }
};
int main(){
    Dothi a;
    a.nhap();
    a.dijkstra();
    
    return 0;
}