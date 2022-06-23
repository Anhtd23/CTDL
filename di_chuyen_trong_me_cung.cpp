#include<bits/stdc++.h>
using namespace std;
int a[10][10];
bool solve[10][10];
int D[100];
int n;
typedef struct 
{
    int x, y;
    string a = "";
}runner;
void Try(){
    int x = 1, y = 1;
    a[x][y] = 0;
    queue<runner> c;
    runner run = {1, 1, ""};
    c.push(run);
    runner tmp;
    while (!c.empty())
    {
        tmp = c.front();
        c.pop();
        if(tmp.x == n && tmp.y == n) cout<<tmp.a<<" ";
        else{
            solve[tmp.x][tmp.y] = 1;
            if(a[tmp.x-1][tmp.y] && tmp.x - 1 >= 1 && solve[tmp.x-1][tmp.y]) c.push(runner{tmp.x-1, tmp.y, tmp.a+"U"});  
            if(a[tmp.x][tmp.y-1] && tmp.y - 1 >= 1 && solve[tmp.x][tmp.y-1]) c.push(runner{tmp.x, tmp.y-1, tmp.a+"L"});  
            if(a[tmp.x][tmp.y+1] && tmp.y + 1 <= n && solve[tmp.x][tmp.y+1]) c.push(runner{tmp.x, tmp.y+1, tmp.a+"R"});  
            if(a[tmp.x+1][tmp.y] && tmp.x + 1 <= n && solve[tmp.x+1][tmp.y]) c.push(runner{tmp.x+1, tmp.y, tmp.a+"D"});
            solve[tmp.x][tmp.y] = 0;
            a[tmp.x][tmp.y] = 0;
            cout<<c.size()<<endl;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {   
        cin>>n;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= n ; j++) cin>>a[i][j];
        }
        Try();
        cout<<endl;
    }
    

    return 0;
}