#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define MAXN 50001 
struct Node{
    long long lazy;
    long long val;
    Node(){
        lazy = val = 0;
    }
};
Node nodes[4 * MAXN];
void down(int id){
    nodes[2*id].lazy += nodes[id].lazy;
    nodes[2*id].val += nodes[id].lazy;
    nodes[2*id+1].lazy += nodes[id].lazy;
    nodes[2*id+1].val += nodes[id].lazy;
    nodes[id].lazy = 0;
}
long long get(int id, int l, int r, int u, int v){
    if(r < u || l > v) return 0;
    if( l >= u && r <= v ) return nodes[id].val;
    int mid = (l+r)/2;
    down(id);
    return max(get(id*2,l , mid, u, v), get(id*2+1, mid+1 , r, u,v));
}
void update(int id, int l, int r, int u, int v, int k){
    if(r < u || l > v) return;
    if( l >= u && r <= v ){
        nodes[id].lazy += k;
        nodes[id].val += k;
        return;
    }
    int mid = ( l + r) /2;
    down(id);
    update(id*2, l, mid, u, v, k);
    update(id*2 + 1 ,mid+1, r,u, v, k);
    nodes[id].val = max(nodes[id*2].val , nodes[id*2+1].val);
}
void solve(){
    int n;
    cin>>n;
    int Q;
    cin>>Q;
    int tmp1, tmp2, tmp3, tmp4;
    for(int i = 0 ; i < Q ; i++){
        cin>>tmp1;
        if(tmp1){
            cin>>tmp2>>tmp3;
            cout<<get(1, 0, n-1,tmp2, tmp3)<<endl;
        }
        else{
            cin>>tmp2>>tmp3>>tmp4;
            update(1, 0, n-1, tmp2, tmp3, tmp4);
        }
    }
}
int main(){
    solve();
    return 0;
}