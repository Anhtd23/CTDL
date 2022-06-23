#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
struct Node{
    int sum, lazy;
}nodes[MAX*4];
void down(int id, int l, int r,int mid){
    if(nodes[id].lazy % 2 == 1 )
    {
        nodes[id*2].lazy++;
        nodes[id*2].sum = (mid - l + 1) - nodes[id*2].sum;
        nodes[id*2+1].lazy++;
        nodes[id*2+1].sum = (r - mid) - nodes[id*2+1].sum;
    }
    nodes[id].lazy = 0;
}
void update(int id, int l, int r, int u, int v){
    if(l > v || r < u ) return;
    if( l >= u && r <= v ) {
        nodes[id].lazy++;
        nodes[id].sum = (r - l + 1 ) - nodes[id].sum;
        return;
    }
    int mid = (l+r) /2;
    down(id, l , r, mid);
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    nodes[id].sum = nodes[id*2].sum + nodes[id*2+1].sum;
}
int get(int id , int l, int r, int u, int v){
    if(l > v || r < u ) return 0;
    if(l >= u &&  r <= v ){
        return nodes[id].sum;
    }
    int mid = (l + r ) /2;
    down(id, l , r, mid);
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}
void solve(){
    int Q, n;
    cin>>n>>Q;
    int tmp1, tmp2, tmp3;
    for(int i = 0 ; i < Q ; i++){
        cin>>tmp1>>tmp2>>tmp3;
        if(!tmp1) update(1, 0, n-1, tmp2-1, tmp3-1);
        else cout<<get(1, 0, n-1, tmp2-1, tmp3-1)<<endl;
    }
}
int main(){
    solve();

    return 0;
}