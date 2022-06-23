#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int truoc = -1, ans = -1;
        int i = 0, tmp;
        for(i = 0 ; i < n  ; i++) {
            cin>>tmp;
            if(tmp < truoc){
                ans = i;
                break;
            }
            truoc = tmp;
        }
        i++;
        while(i < n) {
            cin>>tmp;
            i++;}
        if(ans == -1) cout<<0<<endl;
        else cout<<ans<<endl;
    }
    

    return 0;
}