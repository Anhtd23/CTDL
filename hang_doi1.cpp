#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        queue<int> q;
        while(n--){
            int lenh;
            cin>>lenh;
            switch (lenh)
            {
                case 1:
                    cout<<q.size()<<endl;
                    break;
                case 2:
                    if(q.empty()) cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
                    break;
                case 3:
                    int tmp;
                    cin>>tmp;
                    q.push(tmp);
                    break;
                case 4:
                    if(!q.empty()) q.pop();
                    break;
                case 5:
                    if(!q.empty()) cout<<q.front()<<endl;
                    else cout<<"-1"<<endl;
                    break;
                case 6:
                    if(!q.empty()) cout<<q.back()<<endl;
                    else cout<<"-1"<<endl;
                    break;
            }
        }
    }
    

    return 0;
}