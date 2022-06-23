#include<bits/stdc++.h>
using namespace std;
string a[200000];
int len;
int minDis(int n, string nguon, string dich){
    len = nguon.length();
    set<string> myset1;
    set<string> :: iterator it;
    bool F[150]= {0};
    char store[150];
    int countA = 0;
    for(int i = 0 ; i < n ; i++){
        myset1.insert(a[i]);
        for(int j = 0 ; j < len ; j++){
            F[a[i][j]] = true;
        }
    }
    for(int i = 0 ;  i < 150 ; i++){
        if(F[i]) store[countA++] = (char)i;
    }
    //for(int i = 0 ; i < countA ; i++) cout<<store[i]<<" ";
    queue<string> q;
    q.push(nguon);
   // myset1.erase(myset1.find(nguon));
    myset1.insert(dich);
    int level = 0;
    string tmp, tmp2;
    while (true)
    {
        level++;
        int s = q.size();
        for(int i = 0 ; i < s ; i++){
            tmp = q.front();
            q.pop();
            if(tmp.compare(dich) == 0) return level;
            for(int i = 0 ; i < 26 ; i++){
                for(int j = 0 ; j < len ; j++){
                    char t = tmp[j];
                    tmp[j] = store[i];
                    it = myset1.find(tmp);
                    if(it != myset1.end()){
                        myset1.erase(it);
                        q.push(tmp);
                    }
                    tmp[j] = t;
                }
            }
        }
    }

}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string nguon, dich;
        cin>>nguon>>dich;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        cout<<minDis(n, nguon, dich)<<endl;
    }
    
    return 0;
}