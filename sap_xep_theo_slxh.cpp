#include<bits/stdc++.h>
using namespace std;
int mark[100001];
typedef struct {
    int x;
    int y;
}xy;
xy store[1001];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        for(int i = 0 ; i < n ; i++) mark[a[i]]++;
        int num = 0;
        for(int i = 0 ; i < 100001; i++){
            if(mark[i]){
                store[num].x = i;
                store[num].y = mark[i];
                num++;
                mark[i] = 0;
            } 
        }
        for(int i = 0 ; i < num - 1; i++){
            for(int j = 0 ; j < num - 1 - i; j++){
                if(store[j].y < store[j+1].y) swap(store[j], store[j+1]);
            }
        }
        for(int i = 0; i < num; i++){
            int j = store[i].y;
            while (j> 0)
            {
                cout<<store[i].x<<" ";
                j--;
            }
        }
        cout<<endl;
    }
    return 0;
}