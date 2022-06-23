#include<bits/stdc++.h>
using namespace std;
class Dothi{
    public:
    int n;
    int a[100][100];
    bool chuaxet[100];
    void nhap(){
        cin>>n;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= n ; j++){
                cin>>a[i][j];
            }
        }
    }
    void reset(){
        for(int i = 1; i <= n ; i++) chuaxet[i] = true;
    }
    bool check(){
        for(int i = 1 ; i <= n ; i++){
            if(chuaxet[i]) return false;
        }
        return true;
    }
    void BFS(int dinh){
        queue<int>c;
        c.push(dinh);
        while(!c.empty()){
            int k = c.front();
            c.pop();
            if(chuaxet[k]){
                chuaxet[k] = false;
                for(int i = 1 ; i <= n ; i++){
                    if(a[k][i] == 1) c.push(i);
                    
                }
            }
        }
    }
    bool kiemTra(){
        for(int i = 1 ; i <= n ; i++){
            reset();
            BFS(i);
            if(check() == false) return false;
        }
        return true;
    }
};
int main(){
    Dothi a;
    a.nhap();
    if(a.kiemTra()) cout<<"strongly connected";
    else cout<<"not strongly connected";
    return 0;
}