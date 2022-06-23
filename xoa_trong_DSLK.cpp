#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> myset;
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin>>tmp;
        if(myset.find(tmp) == myset.end()){
            cout<<tmp<<" ";
            myset.insert(tmp);
        }
    }
    return 0;
}