#include<bits/stdc++.h>
using namespace std;
int k;
bool compareAbs(int a, int b){
    return abs(a-k) < abs(b-k);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n>>k;
        int a[n];
        for(int i = 0 ; i < n ;i++) cin>>a[i];
        for(int i = 0; i < n - 1; i++){
            for(int j = 0 ; j < n - i - 1; j++){
                if(abs(a[j] - k ) > abs(a[j+1]-k)) swap(a[j], a[j+1]);
            }
        }
        for(int i = 0 ; i < n ; i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}