#include<iostream>
using namespace std;

int main(){
    int N, n;
    cin>>N>>n;
    int a[n];
    for(int i = 0; i < n ; i++) cin>>a[i];
    int mark[25000] = {0};
    int max1 = 0;
    for(int i = 0 ; i < n ; i++){
        if(max1 < a[i]) max1 = a[i];
        int j = max1;
        while (j >= 0 )
        {
            if( mark[j] == 1){
                int tmp = j + a[i];
                if(tmp <= N)
                    mark[tmp] = 1;
                if(tmp > max1 && tmp <= N) max1 = tmp;
            }
            j--;
        }
        mark[a[i]] = 1;
    }
    int run1 = N;
    while(!mark[run1] && run1 >= 0) run1--;
    cout<<run1;
    return 0;
}

