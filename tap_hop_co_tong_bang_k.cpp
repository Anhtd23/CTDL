#include<bits/stdc++.h>
using namespace std;
int a[30];
int dem,n, k;
int countA = 0;
string store[1000000];
void in(string a){
    int n = a.length();
    cout<<"{";
    for(int i = 0 ; i < n - 1; i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<"}"<<" ";
}
void Try(int i, int sum, string c){
    if(sum == k){
        store[countA++] = c;
        return;
    }
    for(int j = i ; j < dem ; j++){
        if(sum + a[j] <= k ) {
            Try(j, sum+a[j], c + (char)(a[j] + '0'));
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        countA = 0;
        dem = 0;
        cin>>n>>k;
        set<int> myset;
        set<int> :: iterator it;
        for(int i = 0 ; i < n ; i++) {
            int tmp;
            cin>>tmp;
            myset.insert(tmp);
        }
        for(it = myset.begin(); it != myset.end(); it++){
            a[dem++] = (*it);
        }
        Try(0,0, "");
        if(countA == 0 ) cout<<"-1"<<endl;
        else {
            cout<<countA<<" ";
            for(int i = 0 ; i < countA; i++) in(store[i]);
            cout<<endl;
        }
    }
    

    return 0;
}