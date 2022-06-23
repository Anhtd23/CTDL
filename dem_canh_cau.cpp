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
    int find(){
        queue<int> q;
        int countLt = 0;
        while(check() != 0){
            countLt++;
            int k = check();
            q.push(k);
            while(!q.empty()){
                int c = q.front();
                q.pop();
                if(chuaxet[c]){
                    chuaxet[c] = false;
                    for(int i = 1 ; i <=n ; i++){
                        if(a[c][i] == 1){
                            q.push(i);
                        }
                    }
                }
            }
        }
        return countLt;
    }
    void canhCau(){
        reset();
        int countLt = find();
        for(int i = 1; i <= n ; i++){
            for(int j = i + 1; j <= n ; j++){
                if(a[i][j] == 1){
                    a[i][j] = a[j][i] =  0;
                    reset();
                    if(find() > countLt){
                        cout<<i<<" "<<j<<endl;
                    }
                    a[i][j] = a[j][i] = 1;
                }
            }
        }
    }
};

int main(){
    Dothi a;
    a.nhap();
    a.canhCau();
    
    return 0;
}