#include<bits/stdc++.h>
using namespace std;
typedef struct {
    int value, index, great,less, ans;
}pt;
void leftLess(int a[], int n){
    stack<pt> c;
    int b[n];
    c.push(pt{a[n-1], n-1, -1, -1, -1});
    for(int i = n-2 ; i >= 0 ; i--){
        int tmp = c.top().value;
        if(a[i] > c.top().value){
            while (!c.empty() && a[i] >= c.top().value)
            {
                b[c.top().index] = c.top().ans;
                c.pop();                
            }
            if(!c.empty()){
                c.push(pt{a[i], i,c.top().value,tmp, c.top().less});
            }
            else{
                c.push(pt{a[i], i, -1,tmp, -1});
            }
        }
        else if(a[i] == c.top().value ){
            while (!c.empty() && a[i] >= c.top().value)
            {
                b[c.top().index] = c.top().ans;
                c.pop();                
            }
            int minA = 100000000;
            int j ;
            for( j = i + 1; j < n ; j++){
                if(a[j] < a[i]) break;
            }
            if(j == n ) minA = -1;
            else minA = a[j];
            if(c.empty()){
                c.push(pt{a[i], i, -1,minA, -1});
            }
            else{
                c.push(pt{a[i], i,c.top().value, minA , c.top().less});
            }
        }
        else {
            int minA = 100000000;
            int j ;
            for( j = i + 1; j < n ; j++){
                if(a[j] < a[i]) break;
            }
            if(j == n ) minA = -1;
            else minA = a[j];
            c.push(pt{a[i], i, c.top().value, minA, c.top().less});
        }
    }
    while (!c.empty())
    {
        b[c.top().index] = c.top().ans;
        c.pop(); 
    }
    for(int i = 0 ; i < n ; i++) cout<<b[i]<<" ";
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        leftLess(a, n);
    }
    
    return 0;
}