#include<bits/stdc++.h>
using namespace std;
int nChain, chainHead[10000], chainInd[10000], nBase, posInt[10000], nChild[10000], parent[10000];
vector<vector<int> > a;
int dfs(int u){
    nChild[u] = 1;
    for(int i : a[u]){
        nChild[u] += dfs(i);
    }
    return nChild[u];
}
void hld(int u){
    if(chainHead[nChain] == 0 ) chainHead[nChain] = u;
    chainInd[u] = nChain;
    posInt[u] = ++nBase; 
    int mxVtx = -1;
    for(int i = 0 ; i < a[u].size() ; i++){
        int v = a[u][i];
        if( v != parent[u]){
            if(mxVtx == -1 || nChild[mxVtx] < nChild[v]) mxVtx = v;
        }
    }
    if(mxVtx != -1) hld(mxVtx);
    for (int i = 0; i < a[u].size(); i++) {
		int v = a[u][i];
		if (v != parent[u] && v != mxVtx) {
			nChain++;
			hld(v);
		}
	}
}
int get(int u, int v){
    int uHead = chainHead[u];
    int vHead = chainHead[v];
    if(uHead == vHead){
        if()
    }
}
void solve(){
    nChain = 1;
    hld(1);
}
int main(){
    solve();
    return 0;
}