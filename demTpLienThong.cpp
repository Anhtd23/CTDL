#include<bits/stdc++.h>
using namespace std;
class Dothi{
    public: 
    int a[100][100];
    int n;
    bool chuaxet[100];
    void nhap(){
        cin>>n;
        for(int i = 1 ; i <= n ; i++) {
            for(int j =  1; j <= n ; j++) cin>>a[i][j];
        }
        for(int i = 1 ; i <= n ; i++) chuaxet[i] = true;
    }
    int check(){
        for(int i = 1 ; i <= n ; i++){
            if(chuaxet[i] == true) return i;
        }
        return 0;
    }
    void find(){
        int countLt = 0;
        queue<int>q;
        while(check() != 0){
            int k = check();
            cout<<" k : "<<k<<endl;
            q.push(k);
            countLt++;
            while (!q.empty())
            {
                int c = q.front();
                q.pop();
                if(chuaxet[c]){
                    chuaxet[c] = false;
                    for(int i = 1 ; i <= n ; i++) {
                        if(a[c][i] == 1) q.push(i);
                    }
                }
            }
            
        }
        cout<<countLt<<endl;
    }
};
int main(){
    Dothi D;
    D.nhap();
    D.find();
    return 0;
}