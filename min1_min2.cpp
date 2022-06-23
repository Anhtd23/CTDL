#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        sort(a, a+n);
        int min1 = a[0];
        int min2 = a[0];
        for(int i = 1 ; i < n ; i++){
            if(a[i] > a[0]){
                min2 = a[i];
                break;
            }
        }
        if(min1 == min2) cout<<"-1";
        else cout<<min1<<" "<<min2;
        cout<<endl;
    }
    return 0;
}