#include<bits/stdc++.h>
using namespace std;
int V, E;
vector<vector<int> > a;
bool chuaxet[10000];
int check(){
    for(int i = 1 ; i <= V; i++){
        if(chuaxet[i] == false) return i;
    }
    return 0;
}
bool kt(){
    memset(chuaxet, 0, V+1); 
    queue<int> phiaTrai, phiaPhai;
    int trai[V+1] ={0}, phai[V+1] = {0};
    while(true) {
        int k = check();
        if(k == 0 ) break;
        //cout<<k<<endl;
        phiaTrai.push(k);
        trai[k] = 1;
        chuaxet[k] = 1;
        while(phiaTrai.size() != 0 || phiaPhai.size() != 0){
            int s = phiaTrai.size();    
            for(int i = s-1 ; i >= 0 ; i--){
                for(int j = 0 ; j < a[phiaTrai.front()].size(); j++){
                    if(trai[a[phiaTrai.front()][j]] == 1 ) return false;
                    if(phai[a[phiaTrai.front()][j]] == 0 ) {
                        //cout<<a[phiaTrai.front()][j]<<" ";
                        phai[a[phiaTrai.front()][j]] = 1;
                        phiaPhai.push(a[phiaTrai.front()][j]);
                        chuaxet[a[phiaTrai.front()][j]] = true;
                    }
                }
                phiaTrai.pop();
            }
            s = phiaPhai.size();
            for(int i = s-1 ; i >= 0 ; i--) {
                for(int j = 0 ; j < a[phiaPhai.front()].size(); j++){
                    if(phai[a[phiaPhai.front()][j]] == 1 ) return false;
                    if(trai[a[phiaPhai.front()][j]] == 0 ) {
                        //cout<<a[phiaPhai.front()][j]<<" ";
                        trai[a[phiaPhai.front()][j]] = 1; 
                        phiaTrai.push(a[phiaPhai.front()][j]);
                        chuaxet[a[phiaPhai.front()][j]] = 1;
                    }
                }
                phiaPhai.pop();
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>V>>E;
        int tmp1, tmp2;
        a.clear();
        a.resize(10000);
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            if(tmp1 > V || tmp2 > V ) continue;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        if(kt()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}