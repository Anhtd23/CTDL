#include<bits/stdc++.h>
using namespace std;
string a[102];
char dic[10][10];
int tu, n, m;
bool chuaxet[10][10];
int doc[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ngang[8] = {-1,0, 1 ,-1, 1, -1, 0 , 1};
bool check = true;
bool isWord(string& str)
{
    for (int i = 0; i < tu; i++)
        if (str.compare(a[i]) == 0)
            return true;
    return false;
}
void gene(int x, int y, string& b){
        chuaxet[x][y] = false;
        b += dic[x][y];
        if(isWord(b)){
            cout<<b<<" ";
            check = false;
        }
        for(int i = 0 ; i < 8; i++){
            int themX = x + doc[i];
            int themY = y + ngang[i];
            if(themX >= 1 && themY >= 1 && themX <= n && themY <= m && chuaxet[themX][themY])
                gene(themX, themY, b);
        }
        b.erase(b.length() - 1);
        chuaxet[x][y] = true;
}
void reset(){
    for(int i = 0 ; i <= 5 ; i++){
            for(int j = 0; j <= 5 ; j++) chuaxet[i][j] = true;
    }
}
void Try(){
    reset();
    string b = "";
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= m ; k++){
                gene(j, k, b);
            }
        }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        check = true;
        cin>>tu>>n>>m;
        for(int i = 0 ; i < tu; i++) cin>>a[i];
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++) cin>>dic[i][j];
        }
        Try();
        if(check) cout<<-1;
        cout<<endl;
    }
    

    return 0;
}
