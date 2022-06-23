#include<bits/stdc++.h>
using namespace std;
int a[501][501];
int hoz[501][501];
int ver[501][501];
int n, m;
int maxArea(int b[]){
    stack<int> c;
    int maxArea = 0;
    int tp = 0;
    int i = 1;
    while (i <= m)
    {
        if( c.empty() || b[c.top()] <= b[i]) c.push(i++);
        else{
            tp = c.top();
            c.pop();
            int tmp = b[tp] * (c.empty() ? i : i - c.top() - 1);
            if(tmp > maxArea) maxArea = tmp;
        }
    }
    while (!c.empty())
    {
        tp = c.top();
        c.pop();
        int tmp = b[tp] * (c.empty() ? i : i - c.top() - 1);
        if(tmp > maxArea) maxArea = tmp;
    }
    return maxArea;
}
int maxRectangle(){
    for(int j = 1 ; j <= m ; j++){
        for(int i = 1 ; i <= n ; i++){
            if(a[i][j] == 0 ) ver[i][j] = 0;
            else {
                ver[i][j] = ver[i-1][j] + 1;
            }   
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n; i++){
        ans = max(ans, maxArea(ver[i]));
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                cin>>a[i][j];
            }
        }
        cout<<maxRectangle()<<endl;
    }

    return 0;
}