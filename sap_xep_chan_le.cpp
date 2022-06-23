#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> chan, le;
    int tmp;
    for(int i = 1 ; i <= n ; i++){
        cin>>tmp;
        if( i %  2 == 0 ) chan.push_back(tmp);
        else {
            le.push_back(tmp);
        }
    }
    sort(chan.begin(), chan.end(), greater<>());
    sort(le.begin(), le.end());
    int c = 0, l = 0;
    while (c < chan.size() || l < le.size()) {
        if(l < le.size()) cout<<le[l++]<<" ";
        if(c < chan.size()) cout<<chan[c++]<<" ";
    }
    return 0;
}