#include<bits/stdc++.h>
using namespace std;
int mark[1000000];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        int maxA = *max_element(a, a+n);
        int minA = *min_element(a, a+n);
        for(int i = 0 ; i < n ; i++) mark[a[i]]++;
        int count = 0;
        for(int i = minA ; i <= maxA; i++){
            if(mark[i] == 0) count++;
            else mark[i] = 0;
        }
        cout<<count<<endl;
    }
    return 0;
}