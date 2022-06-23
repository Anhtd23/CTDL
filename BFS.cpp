#include<bits/stdc++.h>
using namespace std;
class Dothi{
    public :
    int a[100][100];
    int n;
    bool chuaxet[100];
    void nhap(){
        cin>>n;
        for(int i = 1; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) cin>>a[i][j];
        }
        for(int i = 1 ; i <= n ; i++) chuaxet[i] = false;
    }
    void findBFS(){
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int c = q.front();
            q.pop();
            if(chuaxet[c] == false){
                cout<<c<<" ";
                chuaxet[c] = true;
                for(int i = 1 ; i <= n ; i++){
                    if(a[c][i] == 1){
                        q.push(i);
                    }
                }
            }
        }
    } 
};
int main(){
    Dothi D;
    D.nhap();
    D.findBFS();
    return 0;
}