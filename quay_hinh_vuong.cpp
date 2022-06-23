#include<bits/stdc++.h>
using namespace std;
typedef vector<int> V;
string quayTrai(string a){
    char tmp = a[3];
    a[3] = a[4];
    a[4] = a[1];
    a[1] = a[0];
    a[0] = tmp;
    return a;
}
string quayPhai(string a){
    char tmp = a[5];
    a[5] = a[2];
    a[2] = a[1];
    a[1] = a[4];
    a[4] = tmp;
    return a;
}

int quayHinhVuong(char a[], char b[]){
    string s1 = "", s2 = "";
    for(int i = 0 ; i < 6; i++) {
        s1 += a[i];
        s2 += b[i];
    }
    queue<string> q;
    q.push(s1);
    set<string> myset;
    int level  = 0;
    while(true){
        int s = q.size();
        //cout<<s<<endl;
        for(int i = 0; i < s;i++){
            string c = q.front();
            q.pop();
            if( !c.compare(s2) ) return level;
            string d = quayTrai(c);
            if(myset.find(d) == myset.end() ){
                myset.insert(d);
                q.push(d);
            }
            d = quayPhai(c);
            if(myset.find(d) == myset.end() ){
                myset.insert(d);
                q.push(d);
            }
        }
        level++;
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        char a[6];
        char b[6];
        for(int i = 0 ; i < 6 ; i++) cin>>a[i];
        for(int i = 0 ; i < 6 ; i++) cin>>b[i];
        cout<<quayHinhVuong(a, b)<<endl;
    }
    return 0;
}