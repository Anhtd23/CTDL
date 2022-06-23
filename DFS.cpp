#include<bits/stdc++.h>
using namespace std;
class DoThi{
    public:
    int n;
    int a[100][100];
    int check[100];
    void nhap(){
        cin>>n;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++) cin>>a[i][j];
        }
        for(int i = 0 ; i < n ; i++) check[i] = true;
    }
    void DFS(){
        stack<int> c;
        if(n == 0 ) return;
        c.push(0);
        check[0] = false;
        cout<<'1'<<" ";
        while(!c.empty()){
            int s = c.top();
            c.pop();
            for(int i = 0 ; i < n ; i++){
                if(a[s][i] == 1 && check[i]){
                    cout<<i + 1<<" ";
                    check[i] = false;
                    c.push(s);
                    c.push(i);
                    break;
                }
            }
        }
    }
};
int main(){
    DoThi a;
    a.nhap();
    a.DFS();
    return 0;
}