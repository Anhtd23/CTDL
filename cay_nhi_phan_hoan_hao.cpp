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
int n, level, check = false;
void cayNhiPhanHoanHao(Node* root,int l){
    if(check == true) return;
    level++;
    if(root->left == NULL ) {
        check = true;
        level = l;
        return;
    }
    cayNhiPhanHoanHao(root->left, l+1);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int x, y;
        char z;
        map<int , Node*> parent;
        Node* root = NULL;
        Node *tmp1, *tmp2;
        for(int i=0; i < n ; i++){
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
        check = false;
        level = 0;
        cayNhiPhanHoanHao(root, 1); 
        //cout<<level<<endl;
        if(n + 1 == pow(2, level) - 1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    

    return 0;
}