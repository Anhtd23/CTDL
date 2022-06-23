#include<bits/stdc++.h>
using namespace std;
string num[500];
string nhanSo(string a, int k){
    string ans = "";
    int len = a.length();
    int carry = 0;
    int sum = 0;
    for(int i = len - 1; i >= 0 ; i--){
        sum = (a[i] - '0') * k + carry;
        carry = sum /10;
        ans += (sum % 10 + '0');
    }
    reverse(ans.begin(), ans.end());
    if(carry > 0) {
        ans = to_string(carry) + ans;
    }
    return ans;
}
string chiaSo(string a, int k){
    int n = a.length();
    int sum = 0;
    string ans = "";
    for(int i = 0 ; i < n ; i++){
        sum = sum * 10 + (a[i]-'0');
        ans += (sum / k + '0');
        sum %= k;
    }
    int beg = ans.find_first_not_of('0');
    if(beg > 0) ans.erase(0, beg);
    return ans;
}
string catalan(int n){
    if(num[n].size() != 0 ) return num[n];
        num[n] = chiaSo(nhanSo(catalan(n-1), 2 * (2 * n - 1)), n + 1);
        return num[n];
}
int main(){
    int t;
    cin>>t;
    num[0] = "1";
    num[1] = "1";
    while (t--)
    {
        int n;
        cin>>n;
        cout<<catalan(n)<<endl;
    }
    
    return 0;
}