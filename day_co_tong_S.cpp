#include<bits/stdc++.h>
using namespace std;
int n, k, max1 = 0;
int mark[40000];
int check(int a[]){
    max1 = 0;
        for(int i = 0 ; i < n ; i++){
            mark[a[i]] = 1;
            if(max1 < a[i]) max1 = a[i];
            int j = max1;
            while (j >= 0 )
            {
                if( mark[j] == 1){
                    int tmp = j + a[i];
                    if(tmp == k) {
                        return 1;
                    }
                    mark[tmp] = 1;
                    if(tmp > max1) max1 = tmp;
                }
                j--;
            }
        }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        memset(mark, 0, max1*4);
        if(check(a)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}