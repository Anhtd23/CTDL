#include<bits/stdc++.h>
using namespace std;
int n;
int store[30] = {2 , 3 , 5, 7 , 11, 13, 17, 19, 23, 29, 31, 37};
long long ans ;

void Try(int i, long long val, int soUoc){
    if(soUoc > n) return;
    if(soUoc == n) ans = min(ans, val);
    else {
        int j = 1; 
        while (val * store[i] < ans)
        {
            val *= store[i];
            Try(i+1, val, soUoc *(j + 1) );
            j++;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        ans = 1e18;
        Try(0, 1, 1);
        cout<<ans<<endl;
    }
    
    return 0;
}