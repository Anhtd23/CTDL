#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> douInt;
void update(int &a, int &b){
    if(b < a) a = b;
}
int numChange(int n){
    int minA = 100000000;
    set<douInt> c;
    set<douInt>::iterator it;
    c.insert(douInt(n, 0));
    douInt tmp;
    while (!c.empty())
    {
        it = c.begin();
        int tmp1 = (*it).first;
        int tmp2 = (*it).second;
        c.erase(it);
        if(tmp1 == 1) update(minA, tmp2);
        else if(tmp1 == 2) update(minA, ++tmp2);
        else if(tmp1 == 3) {
            tmp2 += 2;
            update(minA, tmp2);
        }
        else{
            int s = sqrt(tmp1);
            bool check = true;
            for(int i = 2 ; i <= s; i++){
                if(tmp1 % i == 0){
                    douInt tmp(tmp1/i, tmp2+1);
                    if(c.count(tmp) == 0){
                        c.insert(tmp);
                        check = false;
                    }
                }
            }
            if(check && c.count(douInt(tmp1 - 1, tmp2 + 1)) == 0) c.insert(douInt(tmp1 - 1, tmp2 + 1));
        }
    }
    return minA;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<numChange(n)<<endl;
    }
    

    return 0;
}