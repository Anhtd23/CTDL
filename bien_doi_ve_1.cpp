#include<bits/stdc++.h>
using namespace std;
int n;
int minManipulation(){
    queue<int> q;
    q.push(n);
    int level =0;
    set<int> myset;
    while (true)
    {
        level++;
        int s = q.size();
        for(int i = 0 ; i < s ; i++){
            int c = q.front();
            q.pop();
            if(c == 1) return level - 1;
            if(c % 2 == 0 &&  myset.find(c/2) == myset.end()){
                myset.insert(c/2);
                q.push(c/2);
            }
            if( c % 3 == 0 && myset.find(c/3) == myset.end()){
                myset.insert(c/3);
                q.push(c/3);
            }
            if(myset.find(c-1) == myset.end()){
                myset.insert(c-1);
                q.push(c-1);
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<minManipulation()<<endl;
    }

    return 0;
}