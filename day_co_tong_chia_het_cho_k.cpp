#include<bits/stdc++.h>
using namespace std;
int n, k;
int store[10000];
int a[10000];
int maxLen = 0, maxA = 0;
int maxLenSque(){
    memset(store, 0, 4 * 10000);
    maxLen = 0;
    maxA = a[0];
    store[maxA] = 1;
    for(int i = 1 ; i < n ; i++){
        for(int j = maxA; j >= 0; j--){
            if(j > 0){
                if(store[j] > 0 ){
                    int index = j + a[i];
                    store[index] = max(store[index], store[j] +1);
                }
            }
            else{
                store[a[i]] = max(store[a[i]], 1);
            }
        }
        maxA += a[i];
    }
    for(int i = 1 ; i <= maxA; i++){
        if(i % k == 0 && store[i] > 0) maxLen = max(maxLen, store[i]);
    }
    return maxLen;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        cout<<maxLenSque()<<endl;
    }
    return 0;
}