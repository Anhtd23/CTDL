#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int n;
typedef pair<int, int> douInt;
void find(){
    map<int, int > myMap;
    map<int, int> ::iterator it;
    for(int i = 0 ; i < n ; i++){
        it = myMap.find(a[i]);
        if(it == myMap.end()) myMap.insert(douInt(a[i], 1));
        else {
            int tmp = (*it).second;
            myMap.erase(it);
            myMap.insert(douInt(a[i], tmp+1));
        }
    }
    int store[n];
    for(int i = 0 ; i < n ; i++){
        store[i] = myMap[a[i]];
    }
   /* for(int i = 0 ; i < n ; i++) {
        cout<<store[i]<<" ";
    }
    cout<<endl;*/
    stack<douInt> c;
    int F[n];
    for(int i = n - 1; i >= 0 ; i--){
        while (!c.empty() && store[i] >= c.top().first) c.pop();
        if(c.empty()) F[i] = -1;
        else {
            F[i] = a[c.top().second];
        }
        c.push(douInt(store[i], i));
    }
    for(int i = 0 ; i < n ; i++) {
        cout<<F[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        find();
    }
    

    return 0;
}