#include<bits/stdc++.h>
using namespace std;
int V, E;
int a[1001][2];
bool chuaxet[1001];
void reset(){
    for(int i = 1; i <= V ; i++){
        chuaxet[i] = true;
    }
}
bool check(int k){
    for(int i = 0 ; i < E ; i++){
        if(i != k){
            chuaxet[a[i][0]] = false;
            chuaxet[a[i][1]] = false;
        }
    }
    for(int i = 1 ; i <= V ; i++){
        if(chuaxet[i]) return false;
    }
    return true;
}
void canhCau(){
    for(int i = 0 ; i < E; i++){
        reset();
        if(!check(i)) cout<<a[i][0]<< " "<<a[i][1]<<" ";
    }
}
int main(){ 
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E;
        int tmp1, tmp2;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[i][0] = tmp1;
            a[i][1] = tmp2;
        }
        canhCau();
        cout<<endl;
    }
    

    return 0;
}