#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
int bit[MAX], n;
int get(int p){
    int i = p, sum = 0;
    while (i > 0 )
    {
        sum += bit[i];
        i -= (i & (-i));
        cout<<i<<endl;
    }
    return sum;
}
void update(int u, int v){
    int i = u;
    while(i <= n){
        bit[i] += v;
        i += (i & (-i));
        cout<<i<<endl;
    }
}
void solve(){
    cin>>n;
    int Q;
    cin>>Q;
    int tmp1, tmp2, tmp3;
    for(int i = 0 ; i < Q ; i++){
        cin>>tmp1;
        if(tmp1){
            cin>>tmp2;
            cout<<get(tmp2)<<endl;
        }
        else{
            cin>>tmp2>>tmp3;
            update(tmp2, tmp3);
        }        
    }
}
int main(){
    solve();

    return 0;
}