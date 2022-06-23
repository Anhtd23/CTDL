#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000];
int c[1000];
int n;
int findSwap(int i){
    int tmp = 0;
    for(int j = i + 1 ; j < n ; j++){
        if(c[i] == b[j] && b[i] == c[j]) return j;
        if(c[i] == b[j] ) tmp = j;
    }
    return tmp;
}
int minSwap(){
    int ans = 0;
    for(int i = 0 ; i < n - 1; i++){
        if(b[i] == c[i]) continue;
        else {
            int k = findSwap(i);
            ans++;
            swap(b[i], b[k]);            
        }
    }
    return ans;
}
int main(){
    cin>>n;
    cin>>a;
    for(int i= 0;  i < n ; i++){
        if(a[i] == 'X') c[i] = b[i] = 1;
        else if(a[i] == 'T') c[i] = b[i] = 2;
        else c[i] =  b[i] = 3;
    }
    sort(c, c+n);
    cout<<minSwap();
    return 0;
}