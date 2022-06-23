#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
struct Node{
    int maxA, minA, kt, dauTru, dauCong;
    Node(){}
    Node(int maxA, int minA, int kt, int dauTru, int dauCong){
        this->maxA = maxA;
        this->minA = minA;
        this->kt = kt;
        this->dauTru = dauTru;
        this->dauCong = dauCong;
    }
    Node operator + (const Node& other){
        Node res;
        res.minA = min(this->minA,this->kt + other.minA);
        res.maxA = max(this->maxA, this->kt + other.maxA);
        res.dauCong = this->dauCong + other.dauCong;
        res.dauTru = this->dauTru + other.dauTru;
        res.kt = this->kt + other.dauCong - other.dauTru;
        return res;
    }
};
Node nodes[4 * MAX];
string a;
void build(int id , int l, int r ){
    if(l == r ){
        if(a[l] == '-') nodes[id] = Node(0, -1, -1, 1, 0);
        else nodes[id] = Node(1, 0, 1, 0, 1);
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    nodes[id] = nodes[2*id] + nodes[2*id+1];
}
Node get(int id, int l , int r, int u, int v){
    if(l > v || r < u) return Node(0, 0, 0, 0, 0);
    if(l >= u && r <= v) return nodes[id];
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}
void solve(){
    cin>>a;
    int n = a.length();
    int Q;
    cin>>Q;
    build(1, 0, n-1);
    for(int i = 0 ; i < Q ; i++){
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        Node tmp = get(1, 0, n-1, tmp1-1, tmp2-1);
        cout<<tmp.maxA - tmp.minA + 1<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}