#include<bits/stdc++.h>
using namespace std;
int mark[1001];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n], b[m];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        for(int i = 0 ; i < m ; i++) cin>>b[i];
        for(int i = 0 ; i <= 1000; i++) mark[i] = 0;
        for(int i = 0 ; i < m ; i++) mark[b[i]]++;
        for(int i = 999 ; i >= 0; i--){
            mark[i] += mark[i+1];
        }
        //for(int i = 0 ; i <= 1000; i++) cout<<mark[i]<<" ";
        int count = 0;
        for(int i = 0; i < n ; i++){
            if(a[i] == 0 ) continue;
            if(a[i] == 1) count += mark[0]-mark[1];
            else if(a[i] == 2){
                count += mark[0]-mark[2];
                count+= mark[5];
            }
            else {
                count+= mark[0] - mark[2];
                if(a[i] == 3) count += mark[2]-mark[3];
                count += mark[a[i]+1];
            }
        }
        cout<<count<<endl;
    }
    return 0;
}