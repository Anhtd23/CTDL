#include<bits/stdc++.h>
using namespace std;
long long countA = 0;
typedef struct{
    char x;
    int z;
}ngoac;
void swap(char &x, char&y){
    int tmp = x;
    x =  y;
    y = tmp;
}
long long demNgoac(string a){
    int n = a.length();
    stack<int> c;
    ngoac d[n];
    for(int i =  0; i < n ; i++){
        if( a[i] == '['){
            c.push(i);
            d[i].z  = -1;
            d[i].x = '[';
        }
        else{
            d[i].x = ']';
            d[i].z = -1;
            if(!c.empty()){
                d[c.top()].z = i;
                d[i].z = c.top();
                c.pop();
            }
        }
    }   
    for(int i = 0 ; i < n ; i++){
        if(d[i].z == -1){
            int j = i;
            while (d[j].x == ']' && d[j+1].x == ']' && j < n) j++;
            swap(d[j].x, d[j+1].x);
            d[j].z = j+1;
            if( d[j+1].z != -1){
                d[d[j+1].z].z = -1;
            }
            d[j+1].z = j;
            i--;
            countA++;
        }
    }
    return countA;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        countA =0 ;
        cout<<demNgoac(a)<<endl;
    }
    return 0;
}