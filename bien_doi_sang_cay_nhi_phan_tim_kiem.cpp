#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        set<int> mySet;
        int x,y;char z;
        for(int i = 0 ; i < n ; i++){
            cin>>x>>y>>z;
            mySet.insert(x);
            mySet.insert(y);
        }
        vector<int> a(mySet.begin(),mySet.end());
        for(int i = 0 ; i < a.size() ; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    

    return 0; 
}