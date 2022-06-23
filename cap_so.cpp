#include<bits/stdc++.h>
using namespace std;
pair<int, int> a[1000];
int b[1000];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for(int i = 1 ; i <= n ; i++) {
            cin>>a[i].first;
            cin>>a[i].second;
        }
        sort(a+1, a+n+1);
        b[0] = 0;b[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            b[i] = 1;
            for(int j = i-1 ; j >= 1 ; j--){
                if(a[i].first > a[j].second) b[i] = max(b[i], b[j]+1);
            }
        }
        cout<<*max_element(b+1, b+n+1)<<endl;
    }
    return 0;
}