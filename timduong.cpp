#include<bits/stdc++.h>
using namespace std;
class Dothi{
    public:
    int a[100][100];
    int n;
    int x, y, y1;
    bool chuaxetDFS[100];
    bool chuaxetBFS[100];
    int truocDFS[100];
    int truocBFS[100];
    void nhap(){
        cin>>n>>x>>y;
        y1 = y;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ;j <= n ; j++) cin>>a[i][j];
        }
        for(int i = 1 ; i <= n ; i++) chuaxetDFS[i] = true;
        for(int i = 1 ; i <= n ; i++) chuaxetBFS[i] = true;
        for(int i = 1 ; i <= n ; i++) truocDFS[i] = 0;
        for(int i = 1 ; i <= n ; i++) truocBFS[i] = 0;
    }
    void findBFS(){
        queue<int> q;
        q.push(x);
        chuaxetBFS[x] = false;
        while(!q.empty()){
            int c = q.front();
            q.pop();
                for(int i = 1 ; i <= n ; i++){
                    if(a[c][i] == 1 && chuaxetBFS[i]){
                        chuaxetBFS[i] = false;
                        truocBFS[i] = c;
                        q.push(i);
                    }
                }
        }
    }
    void findDFS(){
        stack<int> q;
        q.push(x);
        chuaxetDFS[x] = false;
        while(!q.empty()){
            int c = q.top();
            q.pop();
            for(int i =  1; i <= n ; i++){
                if(a[c][i] == 1 && chuaxetDFS[i]){
                    chuaxetDFS[i] = false;
                    truocDFS[i] = c;
                    q.push(c);
                    q.push(i);
                    break;
                }
            }
        }
    }
    bool print(int truocDFS[], int y){
        if(truocDFS[y] == 0 ) return false;
        else{
            cout<<y<<" ";
            while(truocDFS[y] != x){
                cout<<truocDFS[y]<<" ";
                y = truocDFS[y];
            }
            cout<<x<<endl;
            return true;
        }
    }
    void findRoad(){
        findDFS();
        findBFS();
        if(print(truocDFS, y)){
            print(truocBFS, y1);
        }
        else cout<<"no path";
    }
    
};
int main(){
    Dothi D;
    D.nhap();
    D.findRoad();
    
    return 0;
}