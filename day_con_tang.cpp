#include<bits/stdc++.h>
using namespace std;

int main(){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        int F[n];
        for(int i = 0 ; i < n ; i++){
            F[i] = 1;
            int j = i - 1;
            while (j >= 0)
            {
                if(a[j] < a[i] && F[i] <= F[j]) F[i] = F[j]+1;
                j--;
            }
        }
        int max = 0;
        for(int i = 0; i < n ; i++) if(max < F[i]) max = F[i];
        cout<<max<<endl;
    
    return 0;
}