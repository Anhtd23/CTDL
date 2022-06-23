#include<bits/stdc++.h>
using namespace std;
#define MAX 100007
long long a[MAX], bit1[MAX], bit2[MAX],diff[MAX], n, Q;
void increase(long long bit[], long long p, long long v){
    long long id = p;
    while(id <= n){
        bit[id] += v;
        id += (id & (-id));
    }
}
void update(long long  l, long long r, long long v){
    increase(bit1, l, (n-l + 1) * v);
    increase(bit1, r + 1 , - (n - r) * v);
    increase(bit2, l, v);
    increase(bit2, r + 1 , -v);
}
long long getSum( long long bit[], int p){
    long long id = p;
    long long sum = 0;
    while (id > 0)
    {
        sum += bit[id];
        id -= (id & (-id));
        //cout<<id<<endl;
    }
    return sum;
}
long long getPrefixSum( int u){
    return getSum(bit1, u) - getSum(bit2, u) * (n - u);
}
long long get(int tmp1, int tmp2){
    return getPrefixSum(tmp2) - getPrefixSum(tmp1-1);
}
void solve(){
    cin>>n>>Q;
    for(int i = 1 ; i <= n ; i++) {
        cin>>a[i];
        diff[i] = a[i] - a[i-1];
        increase(bit1, i, (n - i +1) * diff[i]);
        increase(bit2, i, diff[i]);
    }
    long long tmp1, tmp2, tmp3, tmp4;
    for(int i = 0 ; i < Q; i++){
        cin>>tmp1;
        if(tmp1 == 1 ){
            cin>>tmp2>>tmp3>>tmp4;
            update(tmp2, tmp3, tmp4);
        }
        else {
            cin>>tmp2>>tmp3;
            cout<<get(tmp2, tmp3)<<endl;
        }
    }
}
int main(){
    solve();

    return 0;
}