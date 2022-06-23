#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
}node;
int n1, n2;
void nhapAo(int k){
    int x, y;char z;
    for(int i = 0 ; i < k ; i++) cin>>x>>y>>z;
}
bool solve(){
    cin>>n1;
        int x, y;
        char z;
        map<int , Node*> parent;
        Node* root = NULL;
        Node *tmp1, *tmp2;
        for(int i=0; i < n1 ; i++){
            cin>>x>>y>>z;
            if(parent.find(x) == parent.end()){
                tmp1 = new Node(x);
                parent[x] = tmp1;
                if(root == NULL) root = tmp1;
            }
            else {
                tmp1 = parent[x];
            }
            tmp2 = new Node(y);
            if(z == 'L') tmp1->left = tmp2;
            else tmp1->right = tmp2;
            parent[y] = tmp2;
        }
    cin>>n2;
    if(n1 != n2){
        nhapAo(n2);
        return false;
    }
    for(int i = 0 ; i < n2 ; i++){
        cin>>x>>y>>z;
        if(parent.find(x) == parent.end()){
            nhapAo(n2 - i -1);
        }
        else{
            Node* c = parent[x];
            if(z == 'L'){
                if(c->left->data != y){
                    nhapAo(n2 - i -1);
                    return false;
                }
            }
            else {
                if(c->right->data != y){
                    nhapAo(n2 - i -1);
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}