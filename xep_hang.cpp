#include<bits/stdc++.h>
using namespace std;
#define MAX 50001
int a[MAX];
struct Node{
    int lMax, lMin;
    Node(){}
    Node(int lMax, int lMin){
        this->lMax = lMax;
        this->lMin = lMin;
    }
    Node operator + (const Node& other){
        Node res;
        res.lMax = max(lMax, other.lMax);
        res.lMin = min(lMin, other.lMin);
        return res;
    }
}nodes[MAX*4];
void build(int id, int l , int r){
    if(l == r) {
        nodes[id] = Node(a[l], a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    nodes[id] = nodes[id*2] + nodes[id*2+1];
}
Node get(int id, int l , int r, int u, int v){
    if( l > v || r < u) return Node(-2000000, 2000000);
    if( l >= u && r <= v ) return nodes[id];
    int mid = (l + r) /2;
    return get(id * 2 , l, mid, u, v) + get(id * 2 + 1 , mid + 1 , r, u, v);
}
void solve(){
    int n, Q;
    cin>>n>>Q;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    build(1, 0, n-1);
    int tmp1, tmp2;
    for(int i = 0 ; i < Q; i++){
        cin>>tmp1>>tmp2;
        Node tmp = get(1, 0, n-1, tmp1-1, tmp2-1);
        cout<<tmp.lMax - tmp.lMin<<endl;
    }

}
int main(){
    solve();
    return 0; 
}