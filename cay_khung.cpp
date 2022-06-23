#include<bits/stdc++.h>
using namespace std;
class Dothi{
    public:
    int a[100][100];
    int chuaxet[100];
    int n, v;
    void nhap(){
        cin>>n>>v;
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) cin>>a[i][j];
        }
    }
    void reset(){
        for(int i = 1 ; i <=  n ; i++) chuaxet[i] = false;
    }
    void BFS(){
        queue<int> q;
        q.push(v);
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            for(int i = 1 ; i <= n ; i++){
                if(a[tmp][i] == 1) {
                    if(!chuaxet[i]){
                        cout<<tmp<<" "<<i<<endl;
                        q.push(i);
                        chuaxet[i] = true;
                    }
                }
            }
        }
    }
    void DFS(int v){
        for(int i = 1 ; i <= n ; i++){
            if(a[v][i] == 1 && !chuaxet[i]){
                cout<<v<<" "<<i<<endl;
                chuaxet[i] = true;
                DFS(i);
            }
        }
    }
    void cay_khung(){
        reset();
        chuaxet[v] = true;
        cout<<"DFS tree"<<endl;
        DFS(v);
        cout<<"BFS tree"<<endl;
        BFS();
    }
};
int main(){
    Dothi a;
    a.nhap();
    a.cay_khung();
    
    return 0;
}