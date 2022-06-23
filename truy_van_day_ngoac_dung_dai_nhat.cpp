#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
string a;
int Q, n;
struct Node{
    int optimal;
    int open;
    int close;
    Node(){}
    Node(int op, int o, int c){
        optimal = op;
        open = o;
        close = c;
    }
};
Node *st = new Node[MAXN * 4];
Node operator + (const Node& l, const Node& r){
        Node res;
        int tmp = min(l.open, r.close);
        res.optimal = l.optimal + r.optimal + tmp;
        res.open = l.open + r.open - tmp;
        res.close = l.close + r.close - tmp;
        return res;
}
void build(int id , int l, int r){
    if(l == r){
        if(a[l] == '('){
            st[id] = Node(0, 1, 0);
        }
        else st[id] = Node(0, 0 , 1);
        return;
    }
    int mid = (l + r) /2;
    build(id * 2, l , mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
}
Node query(int id , int l, int r, int u, int v){
    if( l > v || r < u) return Node(0, 0, 0);
    if( u <= l && v >= r) return st[id];
    int mid = (l + r ) /2;
    return query(id*2 , l , mid, u , v) + query(id * 2 + 1 , mid+1, r, u, v);
}
void solve(){
    cin>>a;
    n = a.length();
    build(1, 0, n-1);
    cin>>Q;
    for(int i = 0 ; i < Q ; i++){
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        Node s = query(1, 0, n-1, tmp1-1, tmp2-1);
        cout<<s.optimal*2<<endl;
    }
}
int main(){
    solve();
    
    return 0;
}