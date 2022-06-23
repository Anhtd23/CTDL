#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        int a[k];
        for(int i = 0 ; i < k ; i++)  cin>>a[i];
        int i = k-1;
        while (a[i] - 1 == a[i-1] && i >= 1) i--;
        if( i == 0 && a[0] == 1){
           for(int i = n-k ; i < n ; i++) cout<<i+1<<" ";
           cout<<endl;
        }
        else {
            a[i]--;
            int j = k-1;
            while (j > i)
            {
                a[j] = n - k + j+1;
                j--;
            }
            for(int i = 0 ; i < k ; i++) cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    

    return 0;
}