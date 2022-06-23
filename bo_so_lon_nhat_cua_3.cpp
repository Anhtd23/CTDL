#include<bits/stdc++.h>
using namespace std;
typedef pair<vector<int>, int> VI;
vector<int> maxVal(int sum, vector<int> store ){
   // cout<<sum<<endl;
    queue<VI> q;
    q.push(VI(store, sum));
    while(!q.empty()){
        VI c = q.front();
        q.pop();
        //for(int i = 0 ; i <= 9 ; i++) cout<<c.first[i]<<" ";
        //cout<<endl;
        if(c.second % 3 == 0 ) return c.first;
        for(int i = 1 ; i <= 9 ; i++){
            if(c.first[i] > 0 && sum - i >= 3){
                c.first[i]--;
                q.push(VI(c.first, sum - i));
                c.first[i]++;
            }
        }
    }
    vector<int> tmp(1, -1);
    return tmp;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int tmp;
        vector<int> store(10, 0);
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>tmp;
            sum += tmp;
            store[tmp]++;
        }
        vector<int> a = maxVal(sum, store);
        if(a.size() == 1 ){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 9 ; i >= 0 ; i--){
            for(int j = 0; j < a[i]; j++) cout<<i;
        }
        cout<<endl;
    }
    return 0;
}