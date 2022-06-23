#include<bits/stdc++.h>
using namespace std;
long long D[100000];
int u2 = 1, u3 = 1, u5 = 0;
int countA = 3;
long long ugly(int n){
    if(D[n] != 0 ) return D[n];
    while (countA <= n)
    {
        long long tmp1 = D[u2] * 2;
        long long tmp2 = D[u3] * 3;
        long long tmp3 = D[u5] * 5;
        D[countA] = min(tmp1, min(tmp2, tmp3));
        if(tmp1 == D[countA]) u2++;
        if(tmp2 == D[countA]) u3++;
        if(tmp3 == D[countA]) u5++;
        countA++;
    }
    return D[n];
}
int main(){
    int t;
    cin>>t;
    D[0] = 1;
    D[1] = 2;
    D[2] = 3; 
    while (t--)
    {
        int n;
        cin>>n;
        cout<<ugly(n-1)<<endl;
    }
    return 0;
}