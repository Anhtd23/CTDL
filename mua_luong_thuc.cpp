#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int N, S, M;
        cin>>N>>S>>M;
        int buyday = S - S/7;
        int need = M * S;
        int can = N * buyday;
        if(can < need) cout<<-1;
        else{
            if(need % N == 0){
                cout<<need / N;
            }
            else cout<<need/N + 1;
        }
        cout<<endl;
    }
    return 0;
}