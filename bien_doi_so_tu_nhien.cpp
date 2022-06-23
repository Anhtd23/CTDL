#include<bits/stdc++.h>
using namespace std;
int changeNum(int n){
    queue <int> q;
    set <int> myset;
    myset.insert(n);
    q.push(n);
    int level = 0;
    while (true)
    {
        int k = q.size();
        for(int i = 0 ; i < k; i++){
            int tmp = q.front();
            q.pop();
            if(tmp == 2 ) return level + 1;
            int s = sqrt(tmp);
            for(int j = 2 ; j <= s; j++){
                if(tmp % j == 0 && myset.count(tmp/j) == 0){
                    q.push(tmp/j);
                    myset.insert(tmp/j);
                }
            }
            if(myset.count(tmp-1) == 0) {
                myset.insert(tmp-1);
                q.push(tmp-1);
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
        cout<<changeNum(n)<<endl;   
    }
    return  0;
}