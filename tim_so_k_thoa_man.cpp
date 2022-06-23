#include<bits/stdc++.h>
using namespace std;
int store[100000];
int chuyen(string a){
    stringstream ss(a);
    int tmp;
    ss>>tmp;
    return tmp;
}
bool check(string a){
    int len = a.length();
    bool kt[6] = {0};
    for(int i = 0 ; i < len ; i++){
        if(kt[a[i] - '0'] || a[i] > '5') return false;
        else kt[a[i] - '0'] = true;
    }
    return true;
}
void demNhoHon(){
    queue<string> q;
    q.push("1"); q.push("2"); q.push("3"); q.push("4"); q.push("5");
    int countA = 0;
    while (!q.empty())
    {
        string tmp = q.front();
        if(tmp.length() > 5) return;
        q.pop();
        if(check(tmp)) {
            countA++;
            store[chuyen(tmp)] = countA;
        }
        for(int i = 0 ; i <= 5 ; i++){
            char add = i + '0';
            q.push(tmp + add);
        }
    }
}

long long findNum(string l, string r){
    int n1 = chuyen(l);
    while (store[n1] == 0) n1--;
    int n2 = chuyen(r);
    while (store[n2] == 0) n2--;
    int tmp = store[n2] - store[n1];
    if(check(l)) tmp++;
    return tmp;
}
int main(){
    int t;
    cin>>t;
    demNhoHon();
    while (t--)
    {
        string l, r;
        cin>>l>>r;
        cout<<findNum(l, r)<<endl;
    }
    

    return 0;
}