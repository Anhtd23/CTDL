#include<bits/stdc++.h>
using namespace std;
string a;
void goMayTinh(){
    list<int> myList;
    int n = a.length();
    list<int> :: iterator tmp;
    auto it = myList.begin();
    for(int i = 0 ; i < n; i++){
        if(a[i] == '<'){
            if(it != myList.begin()) --it;
        }
        else if(a[i] == '>'){
            if(it != myList.end()) ++it;
        }
        else if(a[i] == '-'){
            if(myList.empty()) continue;
            if(it != myList.end() && it != myList.begin()) {
                it = myList.erase(--it);
            }
            else {
                myList.pop_back();
                it = myList.end();
            }
        }
        else {
            myList.emplace(it, a[i]);
        }    
    }
    for(tmp = myList.begin() ; tmp != myList.end(); tmp++){
        cout<<(char)((*tmp));
    }
}
int main(){
    
    getline(cin, a);
    goMayTinh();
    cout<<1<<endl;
    return 0;
}