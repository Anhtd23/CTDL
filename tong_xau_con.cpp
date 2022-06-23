#include<bits/stdc++.h>
using namespace std;
long long mark[15];
long long sumSeq(string a){
    int n = a.length();
    mark[0] = a[0] - '0';
    long long ans = mark[0];
    for(int i = 1 ; i < n ; i++){
        mark[i] = (a[i] - '0') * (i + 1) + mark[i-1] * 10;
        ans += mark[i];
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        cout<<sumSeq(a)<<endl;
    }
    

    return 0;
}