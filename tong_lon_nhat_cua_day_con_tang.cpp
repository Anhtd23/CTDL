#include<bits/stdc++.h>
using namespace std;
int mark[1000];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n; i++) cin>>a[i];
        for(int i = 0 ; i < n ; i++){
            mark[i] = a[i];
            int tmp = 0 ;
            for(int j = i - 1; j >= 0; j--){
                if(a[i] > a[j] ) {
                    tmp = max(tmp , mark[j]);
                }
            }
            mark[i] += tmp;
        }
        cout<<*max_element(mark, mark+n)<<endl;    
    }
    

    return 0;
}