#include<bits/stdc++.h>
using namespace std;
#define MAX 30001
int a[MAX];
struct Node{
    int *a;
    unsigned int n;
    Node(){}
    Node (int t){
        a = new int[1];
        a[0] = t;
        n = 1;
    }
}nodes[4 *MAX];
Node operator + (const Node &a,const Node &b){
    if( a.a == NULL) return b;
    if(b.a == NULL ) return a;
    Node c;
    c.a = new int [a.n + b.n];
    unsigned int i = 0, j = 0, k = 0;
    if(a.a[0] < b.a[0]) c.a[k++] = a.a[i++];
    else c.a[k++] = b.a[j++];
    while (i < a.n && j < b.n)
    {
        if( a.a[i] < b.a[j] ) {
            if(a.a[i] != c.a[k-1] )
                c.a[k++] = a.a[i];
            i++;
        }
        else if( a.a[i] > b.a[j]) {
            if(b.a[j] != c.a[k-1] )
                c.a[k++] = b.a[j];
            j++;
        }
        else{
            if(a.a[i] != c.a[k-1]) c.a[k++] = a.a[i];
            i++;j++;
        }
    }
    if(i == a.n){
        while (j < b.n){
            if(b.a[j] != c.a[k-1]) c.a[k++] = b.a[j];
            j++;
        }
    }
    else{
        while (i < a.n)
        {
            if(a.a[i] != c.a[k-1]) c.a[k++] = a.a[i];
            i++;
        }
    }
    c.n = k;
    return c;
}
Node cloneA;
void build(int id, int l, int r){
    if(l == r ){
        nodes[id]  = Node(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id * 2 + 1, mid+1, r);
    nodes[id] = nodes[id*2] + nodes[id*2+1];
}
Node get(int id, int l, int r, int u, int v){
    if(l  > v || r < u ) return cloneA;
    if( l >= u && r <= v) return nodes[id];
    int mid = (l + r) / 2;
    Node t1 = get(id*2, l,mid, u, v);
    Node t2 = get(id*2+1, mid+1, r, u, v);
    Node t3 = t1 + t2;
    if(t1.a != NULL) delete [] t1.a;
    if(t2.a != NULL) delete [] t2.a;
    return t3;
}
void solve(){
    int n;
    cin>>n;
    int tmp1, tmp2;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    build(1, 0, n-1);
    int Q;
    cin>>Q;
    /*for(int i = 0 ; i < 4 * n ; i++){
        cout<<"i : "<<i<<endl;
        for(int j = 0; j < nodes[i].a.size(); j++){
            cout<<nodes[i].a[j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i  = 0 ; i < Q; i++){
        cin>>tmp1>>tmp2;
        Node t = get(1, 0, n-1, tmp1-1, tmp2-1);
        cout<<t.n<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //if(cloneA.a == NULL) cout<<1<<endl;
    solve();
    return 0;
}