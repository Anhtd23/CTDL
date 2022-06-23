#include<bits/stdc++.h>
using namespace std;
class Dothi{
  public:
    int a[100][100];
    int n;
    bool chuaxet[100];
    
    void nhap(){
        cin>>n;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= n ; j++) cin>>a[i][j];
        }
    }
    void reset(){
        for(int i = 1; i <= n ; i++){
            chuaxet[i] = true;
        }
    }
    int check(){
        for(int i = 1; i <=n ; i++){
            if(chuaxet[i]) return i;
        }
        return 0;
    }
    int find(int b[100][100]){
        int countA = 0;
        queue<int> q;
        while(check() != 0){
            countA++;
            int k = check();
            q.push(k);
                while(!q.empty()){
                    int c = q.front();
                    q.pop();
                    if(chuaxet[c]){
                        chuaxet[c] = false;
                        for(int i = 1; i <= n ; i++){
                            if(b[c][i] == 1){
                                q.push(i);
                            }
                        }
                    }
                }
        }
        return countA;
    }
    void lamMat(int i, int b[100][100]){
        for(int j = 1 ; j <=n ; j++) {
            b[i][j] = 0;
        }
        for(int j = 1 ; j <=n ; j++) {
            b[j][i] = 0;
        }
    }

    void countTru(){
        reset();
        int lt = find(a);
        for(int i = 1 ; i <= n ; i++){
            int b[100][100];
            for(int k = 1 ; k <= n ; k++){
                for(int j = 1; j <= n ; j++) b[k][j] = a[k][j];
            }
            reset();
            chuaxet[i] = false;
            lamMat(i, b);
            int ltTmp = find(b);
            if(ltTmp > lt) cout<<i<<endl;
        }
    }
};
int main(){
    Dothi a;
    a.nhap();
    a.countTru();
    return 0;
}