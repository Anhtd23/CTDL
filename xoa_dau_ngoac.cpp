#include<bits/stdc++.h>
using namespace std;
typedef struct 
{
    int x, y;
}Data;
Data d[205];
string store[10000];
int countA = 0, dem = 0;
void removeDuplicates()
{
  
    int i;
    set<string> s;
    for (i = 0; i < dem; i++) {
        s.insert(store[i]);
    }
    set<string>::iterator it;
    for (it = s.begin(); it != s.end(); ++it)
        cout << *it << endl;
}
void print(string a, string s){
    int len = a.length();
    for(int i = 0 ; i < s.length(); i++) a[d[s[i] - '0'].x] = a[d[s[i] - '0'].y] =  0;
    string tmp = "";
    for(int i = 0 ; i < len ; i++){
        if(a[i] != 0 ) tmp += a[i];
    }
    store[dem++] = tmp;
}
void xoaNgoac(string a){
    int len = a.length();
    Data tmp;
    stack<int> c;
    int level = 0 ;
    for(int i = len-1 ; i >= 0  ; i--){
        if(a[i] == ')'){
            c.push(i);
        }
        else if( a[i] == '('){
            int k = c.top();
            c.pop();
            d[countA].x = i;
            d[countA].y = k;
            countA++;
        }
    }
    vector<string> q;
    q.push_back("0");
    print(a, q[0]);
    for(int i = 1 ; i < countA ; i++){
        int s = q.size();
        char tmp = i + '0';
        string k = "";
        k += tmp;
        print(a, k);
        q.push_back(k);
        for(int j = 0 ; j < s; j++){
            string t = q[j] + tmp;
            print(a, t);
            q.push_back(t);
        }
    }
    sort(store, store+dem);
    removeDuplicates();
}
int main(){
        countA = 0;
        string a;
        cin>>a;
        xoaNgoac(a);
    
    return 0;
}