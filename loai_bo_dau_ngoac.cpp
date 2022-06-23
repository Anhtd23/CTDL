#include<bits/stdc++.h>
using namespace std;
string a;
typedef pair<int, int> douInt;
douInt d[100];
void checkNgoac(){
    stack<int>c;
    int n = a.length();
    for(int i = 0 ; i < n ; i++){
        if(a[i] == '(') c.push(i);
        else if(a[i] == ')') {
            if(!c.empty()){
                d[c.top()].first = 0;
                d[c.top()].second = 1;
                d[i].first = 1;
                d[i].second = 1;
                c.pop();
            }
            else {
                d[i].first = 1;
                d[i].second = -1;
            }
        }
        else {
            d[i].first = 2;
            d[i].second = 0;
        }
    }
    while (!c.empty())
    {
        d[c.top()].first = 0;
        d[c.top()].second = -1;
    }
    int indexOps, indexRight, numSai = 0, numDung = 0;
    for(int i = 0 ; i < n ; i++){
        if(d[i].first == 1 ) {
            if(d[i].second == -1 ) numSai++;
            indexOps = i;
        }
        
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>a;

    }
    
    return 0;
}