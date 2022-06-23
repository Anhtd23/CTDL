#include<bits/stdc++.h>
using namespace std;
int ve1(int n){
    queue<int> q;
    q.push(n);
    set<int>myset;
    myset.insert(n);
    int level = 0;
    while (!q.empty())
    {
        int s = q.size();
        for(int i = 0 ; i < s; i++){
            int k = q.front();
            q.pop();
            if(k == 1) return level;
            if(k % 2 == 0 && myset.count(k/2) == 0){
                q.push(k/2);
                myset.insert(k/2);
            }
            if(k % 3 == 0 && myset.count(k/3) == 0 ){
                q.push(k/3);
                myset.insert(k/3);
            }
            if(k > 1 && myset.count(k-1) == 0 ) {
                q.push(k-1);
                myset.insert(k-1);
            }
        }
        level++;
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<ve1(n)<<endl;
    }
    
    return 0;
}