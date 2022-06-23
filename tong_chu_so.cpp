#include<bits/stdc++.h>
using namespace std;
string s[101][10001];
int n, k;
bool compareA(string a, string b){
    if(a.length() < b.length() ) return true;
    if(b.length() < a.length() ) return false;
    if(a.compare(b) < 0) return true;
    return false;
}
void init(){
    for(char i = '1' ; i <= '9'; i++) s[i-'0'][(i-'0')*(i-'0')] += i;
    for(int i = 2 ; i <= 100 ; i++){
        for(int j = 1 ; j <= 10000; j++){
            for(int k = 9 ; k >= 1 ; k--){
                int x = i - k, y = j - k * k;
                if(x >= 1 && y >= 1 && !s[x][y].empty()){
                    string c = s[x][y] + (char)(k+48);
                    sort(c.begin(), c.end());
                    if(s[i][j].empty()) s[i][j] = c;
                    else {
                        if(compareA(c,s[i][j])) s[i][j] = c;
                    }
                }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    init();
    /*for(int i = 0 ; i <= 100; i++){
        for(int j = 0 ; j <= 100; j++){
            if(!s[i][j].empty()) cout<<s[i][j]<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;
    }*/
    while (t--)
    {
        cin>>n>>k;
        string h = s[n][k];
        if(h.empty()){
            cout<<"-1"<<endl;
            continue;
        }
        for(int i = 0 ; i < h.size() ; i++){
            if(h[i] != '0') cout<<h[i];
        }
        cout<<endl;
    }
    return 0;
}