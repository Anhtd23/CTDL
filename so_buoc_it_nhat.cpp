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
        int count = 0;
        int mark[n] = {0};
        mark[0] = 1;
        for(int i = 1; i < n ; i++){
            int j = i - 1;
            mark[i] = 1;
            while (j >= 0 )
            {
                if(a[i] >= a[j] && mark[j] >= mark[i]) mark[i] = mark[j] + 1; j--;
            }
        }        
        int max = 0;
        for(int i = 0 ; i < n ; i++){
            if(mark[i] > max) max = mark[i];
        }
        cout<<n - max<<endl;
    }
    return 0;
}