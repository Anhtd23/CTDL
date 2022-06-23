#include<bits/stdc++.h>
using namespace std;
int store[500000][2];
bool chuaxet[1001];
int V, E;
void reset(){
    for(int i = 1; i <= V ; i++){
        chuaxet[i] = true;
    }
}
int check(){
    for(int i = 1; i <= V ; i++){
        if(chuaxet[i]) return i;
    }
    return 0;
}
bool find(vector<vector<int>> a){
    /*for(int i = 1 ; i < a.size()  ; i++){
        for(int j = 0 ; j < a[i].size(); j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }*/
    queue<int> q;
    q.push(1);
    while(!q.empty()){                            
        int c = q.front();
        q.pop();
        chuaxet[c] = false;
        for(int i = 0 ; i < a[c].size() ; i++){
            if( chuaxet[a[c][i]]){
                q.push(a[c][i]);
            }
        }
    }
    if(check() == 0 ) return  true;
    else return false;
}
void canhCau(vector<vector<int>> a){
        for(int i = 0 ; i < E; i++){
            reset();
            int tmp1 = store[i][0];
            int tmp2 = store[i][1];
            int k1;
            for(k1 = 0 ; k1 < a[tmp1].size(); k1++){
                if(a[tmp1][k1] == tmp2 ) break;
            }
            int k2;
            for(k2 = 0 ; k2 < a[tmp2].size(); k2++){
                if(a[tmp2][k2] == tmp1) break;
            }
            a[tmp1].erase(a[tmp1].begin() + k1);
            a[tmp2].erase(a[tmp2].begin() + k2);
            if(!find(a)) cout<<tmp1<<" "<<tmp2<<" ";
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E;
        vector<vector<int>> a(V+1);
        for(int i = 0 ; i < E; i++){
            cin>>store[i][0]>>store[i][1];
            a[store[i][0]].push_back(store[i][1]);
            a[store[i][1]].push_back(store[i][0]);
        }
        canhCau(a);
    }
    

    return 0;
}