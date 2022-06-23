#include<bits/stdc++.h>
using namespace std;
int a[100], n, countA, k;
string s[10000];
string chuyen(int n){
    stringstream ss;
    ss<<n;
    string tmp;ss>>tmp;
    return tmp;
}
void in(string a){
    string tmp = "{";
    a.pop_back();
    tmp += a;
    tmp += "}";
    s[countA++] = tmp;
}
void toHop(int i, int sum, string c){
    if(sum > k) return;
    if(sum == k) {
        in(c);
        return;
    }
    for(int j = i; j < n ; j++){
        string tmp = chuyen(a[j]);
        toHop(j, sum + a[j], c + tmp + " ");
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        sort(a, a+n);
        countA = 0;
        toHop(0, 0, "");
        if(countA == 0  ) countA = -1;
        cout<<countA<<" ";
        for(int i = 0 ; i < countA ; i++) cout<<s[i]<<" ";
        cout<<endl;
    }
    

    return 0;
}