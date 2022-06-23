#include<bits/stdc++.h>
using namespace std;
int mark[100000];
int demNgoac(string a){
    int n = a.length();
    /*pair<char, int> d[n];
    for(int i = 0 ; i < n ; i++){
        d[i].first = a[i];
        d[i].second = i;
    }*/
    stack<int>c;
    for(int i = 0 ; i < n ; i++){
        if( a[i] == '(') c.push(i);
        else{
            if(!c.empty()){
                mark[i] = 1;
                mark[c.top()] = 1;
                c.pop();
            }
        }
    }
    stack<char> d;
    //for(int i = 0 ; i < n ; i++) cout<<mark[i]<<" ";
    int nguoc = 0, thuan = 0;
    for(int i = 0 ; i < n ; i++){
        if(mark[i] == 1) {
            mark[i] = 0;
        }
        else{
            if( a[i] == '(') thuan++;
            else nguoc++;
        }
    }
    if(nguoc == 0) return thuan/2;
    if(thuan == 0) return nguoc/2;
    int ans = 0;
    ans = nguoc /2 + nguoc % 2 + thuan /2 + thuan % 2;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        cout<<demNgoac(a)<<endl;
    }
    

    return 0;
}