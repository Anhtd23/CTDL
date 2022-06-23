#include<bits/stdc++.h>
using namespace std;
int V, E;
vector<vector<int> > a;
bool check(int i, int k){
    for(int j = 0 ; j < a[i].size() ; j++){
        if(a[i][j] == k) return true;
    }
    return false;
}
bool perfect(){
    for(int i = 1 ; i <= V; i++){
        int s = a[i].size();
        for(int j = 0 ; j < s-1; j++){
            if(!check(a[i][j], a[i][j+1])) return false;
        }
    }
    return true;
}
int main(){
    int t;      
    cin>>t;
    while(t--){
        cin>>V>>E;
        a.clear();
        a.resize(V+1);
        int tmp1, tmp2;
        for(int i = 0 ; i < E ; i++){
            cin>>tmp1>>tmp2;
            if(tmp1 < tmp2)
                a[tmp1].push_back(tmp2);
            else a[tmp2].push_back(tmp1);
        }
        if(perfect()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}