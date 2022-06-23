#include<bits/stdc++.h>
using namespace std;
int a[100001];
int D[100001];
int n;
typedef pair<int, int> II;
void nhipChungKhoan(){
    stack<II> c;
    c.push(II(a[0], 1));
    D[0] =1;
    for(int i = 1 ; i < n ; i++){
        int countA = 1;
        //cout<<a[i]<<" "<<c.top().first<<" "<<c.top().second<<endl;
        if(a[i] >= c.top().first){
            while (!c.empty() &&  a[i] >= c.top().first){
                countA += c.top().second;
                c.pop();
            }
        }
        c.push(II(a[i], countA));
        D[i] = countA;     
    }
    for(int i = 0 ; i < n ; i++) cout<<D[i]<<" ";
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        nhipChungKhoan();
        cout<<endl;
    }
    

    return 0;
}