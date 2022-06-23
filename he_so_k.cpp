#include<bits/stdc++.h>
using namespace std;
string sumK(string a, string b, int k){
    string ans = "";
    int len1 = a.length();
    int len2 = b.length();
    if(len1 < len2) swap(a, b);
    len1 = a.length();
    len2 = b.length();
    int dis = len1 - len2;
    int div = 0;
    for(int i = len2 - 1 ; i >= 0; i--){
        int iA = i + dis;
        int sum = (a[iA] - '0') + (b[i] - '0') + div;
        ans += ((sum % k) + '0');
        div = sum / k;       
    }
    for(int i = dis - 1; i >= 0 ; i--){
        int sum = (a[i] - '0') + div;
        ans += ((sum % k) + '0');
        div = sum / k;
    } 
    if(div == 1) ans += "1";
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int k;
        string a, b;
        cin>>k>>a>>b;
        cout<<sumK(a, b, k)<<endl;
    }
    

    return 0;
}