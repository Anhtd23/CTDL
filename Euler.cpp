#include<bits/stdc++.h>
using namespace std;
class Dothi{
    public:
    int a[100][100];
    int n, x;
    bool chuaxet[100];int store[100];
    int countA = 0;
    void nhap(){
        cin>>n>>x;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++) cin>>a[i][j];
        }
    }
    void print(){
        for(int i = countA - 1 ; i >= 0 ; i--) cout<<store[i]<<" ";
    }
    void chuTrinh(){
        stack<int> c;
        c.push(x);
        while(!c.empty()){
            int k = c.top();
            int i = 0;
            bool check = true;
            for( i = 1 ; i <= n ; i++){
                if(a[k][i] == 1){
                    c.push(i);
                    a[k][i] = 0;
                    a[i][k] = 0;
                    check = false;
                    break;
                }
            }
            if(check == true){
                c.pop();
                store[countA++] = k;
            }
        }
        print();
    }
};
int main(){
    Dothi D;
    D.nhap();
    D.chuTrinh();
    return 0;
}