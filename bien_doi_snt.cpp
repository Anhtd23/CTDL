#include<bits/stdc++.h>
using namespace std;
bool sangNt[10000];
void sang(){
    for(int i = 2 ; i < 10000; i++){
        if(!sangNt[i]){
            int j = 2;
            while (i * j < 10000)
            {
                sangNt[i*j] = true;
                j++;
            }
        }
    }
}
int numChange(int n, int m){
    queue<int> q;
    q.push(n);
    set<int> myset;
    myset.insert(n);
    int level  = 0;
    while (true)
    {
        level++;
        int l = q.size();
        for(int i = 0 ; i < l ; i++){
            int k = q.front();
            q.pop();
            if(k == m) return level-1;
            int soChia = 1;
            for(int j = 0 ; j <= 3; j++ ){
                soChia *= 10;
                int du = k % (soChia/10);
                int thuong = k / soChia;
                for(int t = 0 ; t <= 9 ; t++){
                    int tmp = (thuong * 10 + t) * (soChia/10) + du;
                    if(tmp < 1000) continue;
                    if(sangNt[tmp] == false && myset.count(tmp) == 0){
                        q.push(tmp);
                        myset.insert(tmp);
                    }
                }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    sang();
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        cout<<numChange(n, m)<<endl;
    }
    return 0;
}