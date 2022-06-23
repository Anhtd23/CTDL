#include<bits/stdc++.h>
using namespace std;
int mark[1001]; 
int C2(int n){
    return n * (n -1)/2;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i = 0; i < n ; i++) cin>>a[i];
        memset(mark, 0, 1001 * 4);
        for(int i = 0; i <  n ; i++){
            mark[a[i]]++;
        }
        int count = 0;
        for(int i = 0 ; i <= k/2 ; i++){
            if(mark[i] && mark[k-i] && i != k - i ) count += mark[i] * mark[k-i];
        }
        if(k % 2 == 0 && mark[k/2] > 1) count += C2(mark[k/2]);
        cout<<count<<endl;
    }
    return 0;
}