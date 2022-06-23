#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int V, E;
        cin>>V>>E;
        vector<vector<int>> a(V+1);
        vector<vector<int>> b(V+1);
        int tmp1, tmp2;
        for(int i = 0 ; i < E ; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            b[tmp2].push_back(tmp1);
        }
        bool check = false;
        for(int i = 1 ; i <= V; i++){
            if(a[i].size() != b[i].size()){
                check = true;
                break;
            }
        }
        if(check) cout<<0;
        else cout<<1;
        cout<<endl;
    }
    
    return 0;
}