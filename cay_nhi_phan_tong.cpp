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
int N, maxA = 0;
int sum(node *root){
    if(root->left == NULL && root->right == NULL) return root->data;
    else{
        int k = 0;
        if(root->left != NULL )  k += sum(root->left);
        if(root->right != NULL ) k += sum(root->right);
        return k + root->data;
    }
}
bool cayNhiPhanTong(node *root){
    if(root->left == NULL && root->right == NULL ) return 1;
    int l = sum(root->left);
    int r = sum(root->right);
    if(l + r == root->data && cayNhiPhanTong(root->left) && cayNhiPhanTong(root->right)) return 1;
    return 0;
}
void pre(node *root){
    cout<<root->data<<" ";
    if(root->left != NULL) pre(root->left);
    if(root->right !=NULL ) pre(root->right);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        map<int , node*> myMap;
        cin>>N;
        int x, y;char z;
        node *root = NULL;
        node* child;
        for(int i = 0 ; i < N ; i++){
            cin>>x>>y>>z;
            Node* parent;
            if(myMap.find(x) == myMap.end()){
                parent = new node(x);
                myMap[x] = parent;
                if(root == NULL) root = parent;
            }
            else {
                parent = myMap[x];
            }
            child = new node(y);
            if(z == 'L') parent->left = child;
            else parent->right = child;
            myMap[y] = child;
        }
        pre(root);
        cout<<cayNhiPhanTong(root)<<endl;
    }
    return 0;
}