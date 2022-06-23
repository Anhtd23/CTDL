#include<bits/stdc++.h>
using namespace std;
bool chuaxet[1005] = {0};
int V, E;
bool kt(){
    for(int i = 1 ; i <= V ; i++){
        if(chuaxet[i] == false) return false;
    }
    return true;
}
/*int eulerCycle(vector<vector<int>> a){
    memset(chuaxet,0, V+1);
    stack<int> c;
    c.push(1);
    int tmp, finish = 0;
    while (!c.empty())
    {
        tmp = c.top();
        bool check = false;
        if(a[tmp].size() == 0 ){
            finish =  
            chuaxet[tmp] = true;
            c.pop();
        }
        else {
            c.push(a[tmp][0]);
            int j = a[tmp][0];
            a[tmp].erase(a[tmp].begin());
            int k = 0;
            for( k = 0 ; k < a[j].size(); k++){
                if(a[j][k] == tmp) break;
            }
            a[j].erase(a[j].begin() + k);
        }
    }
    if(!kt()) return 0;
    else{
        if(finish == 1 ) return 2;
        else return 1;
    }
}
*/
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E;
        vector<vector<int>> a(V+1);
        int tmp1, tmp2;
        for(int i = 0 ; i < E ; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        int chan = 0, le = 0;
        for(int i = 1 ; i <= V ; i++){
            if(a[i].size() % 2 == 1 ) le++;
            else chan++;
        }
        if(le == 0 ) cout<<2;
        else if(le == 2 ) cout<<1;
        else cout<<0;
        cout<<endl;
    }
    
    
    return 0;
}