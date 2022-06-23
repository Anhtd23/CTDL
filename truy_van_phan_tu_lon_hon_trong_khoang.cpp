#include<bits/stdc++.h>
using namespace std;
#define MAX 200001
int a[MAX];
int b[MAX];
int Q, n;
struct Query{
    int k, l , r, site, optimal;
    Query(int i , int j, int m, int s){
        l = i;
        r = j;
        k = m;
        site = s;
    }
    bool operator < (const Query& c){
        return k < c.k;
    }
};
bool compareA(const Query& a, const Query& b){
    return a.site < b.site;
}
void build(int id, int l, int r, int st[]){
    if( l == r){
        st[id] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid, st);
    build(id*2+1, mid+1, r, st);
    st[id] = st[id*2] + st[id*2+1];
}
void update(int id , int l, int r, int site, int st[]){
    if(l > site || r < site) return;
    if(l == r ){
        st[id] = 0;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid,site, st);
    update(id*2+1, mid+1, r, site, st);
    st[id] = st[2*id] + st[2*id +1];
}
int get(int id, int l, int r,int u, int v, int st[]){
    if(l > v || r < u ) return 0;
    if( l >= u && r <= v ) return st[id];
    int mid = (l + r)/2;
    return get(id*2, l , mid, u, v, st) + get(id*2 +1, mid+1, r,u, v, st);
}
void solve(){
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        b[i] = i;
    }
    for(int i = 0 ; i < n - 1 ; i++){
        int index = i;
        int minA = a[i];
        for(int j = i+1 ; j < n ; j++){
            if(minA > a[j] ){
                minA = a[j];
                index = j;
            }   
        }
        if(index != i){
            swap(a[i], a[index]);
            swap(b[i], b[index]);
        }
    }
    cin>>Q;
    vector<Query> queries;
    int l , r, k;
    for(int i = 0 ; i < Q ; i++){
        cin>>l>>r>>k;
        l--;r--;
        queries.push_back(Query(l,r,k, i));
    }
    int st[4*MAX];
    sort(queries.begin(), queries.end());
    int i = 0;
    build(1,0,n-1, st);
    for(int j = 0 ; j < Q; j++){
        while (a[i] <= queries[j].k)
        {
            update(1, l, r, b[i], st);
            i++;
        }
        queries[j].optimal =  get(1, 0, n-1, queries[j].l,queries[j].r, st);
    }
    sort(queries.begin(), queries.end(), compareA);
    for(Query q : queries){
        cout<<q.optimal<<endl;
    }
}
int main(){
    solve();
    return 0;
}