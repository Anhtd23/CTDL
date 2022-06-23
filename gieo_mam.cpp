#include<bits/stdc++.h>
using namespace std;
int a[501][501];
typedef pair<int, int> douInt;
int countDay(int n , int m){
    queue<douInt> q;
    int count1 = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == 1 ) count1++;
            else if(a[i][j] == 2 ) q.push(douInt(i, j));
        }
    }
    int level = 0;
    while (!q.empty() && count1 != 0)
    {
        level++;
        int s = q.size();
        for(int i = 0 ; i < s; i++){
            douInt tmp = q.front();
            q.pop();
            if(tmp.first >= 1 &&  a[tmp.first-1][tmp.second] == 1 ){
                q.push(douInt(tmp.first - 1 , tmp.second));
                a[tmp.first-1][tmp.second] = 2;
                count1--;
            }
            if(tmp.second >= 1 &&  a[tmp.first][tmp.second-1] == 1 ){
                q.push(douInt(tmp.first , tmp.second-1));
                a[tmp.first][tmp.second-1] = 2;
                count1--;
            }
            if(tmp.first < n-1 &&  a[tmp.first+1][tmp.second] == 1 ){
                q.push(douInt(tmp.first + 1 , tmp.second));
                a[tmp.first+1][tmp.second] = 2;
                count1--;
            }
            if(tmp.second < m - 1 &&  a[tmp.first][tmp.second+1] == 1 ){
                q.push(douInt(tmp.first , tmp.second+1));
                a[tmp.first][tmp.second +1] = 2;
                count1--;
            }
        }
    }
    if(count1 > 0) return -1;
    else return level;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j  < m ; j++) cin>>a[i][j];
        }
        cout<<countDay(n, m)<<endl;
    }
    
    return 0;
}