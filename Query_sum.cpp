#include<bits/stdc++.h>
using namespace std;
#define MAX 100007
long long a[MAX], bit[MAX], diff[MAX], n, Q;
void update(int p, int x){
    int id = p;
    while(id <= n){
        bit[id] += x;
        id += (id & (-id));
    }
}
long long get(int tmp2){
    int id  = tmp2;
    long long sum = 0;
    while(id > 0){
        sum += bit[id];
        id -= (id & (-id));
    }
    return sum;
}
void solve(){
    cin>>n;
    cin>>Q;
    for(int i = 1 ; i <= n ; i++) {
        cin>>a[i];
        update(i, a[i]);
    }
    int tmp1, tmp2, tmp3;
    for(int i = 0 ; i < Q; i++){
        cin>>tmp1>>tmp2>>tmp3;
        if(tmp1 == 1 ){
            a[tmp2] += tmp3;
            update(tmp2, tmp3);
        }
        else {
            cout<<get(tmp3) - get(tmp2) + a[tmp2]<<endl;
        }
    }
}
int main(){

    solve();
    return 0;
}