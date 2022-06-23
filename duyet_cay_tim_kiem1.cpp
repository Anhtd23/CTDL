#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
void insert(Node *&root, int x){
    if(root == NULL){
        root = new Node(x);
        return;
    }
    if(x < root->data) insert(root->left, x);
    else insert(root->right, x);
}
int depth(Node* root){
    if(root == NULL) return -1;
    return max(depth(root->left), depth(root->right))+1; 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        Node* root = NULL;
        for(int i = 0 ;  i < n ; i++){
            cin>>a[i];
            insert(root, a[i]);
        }
        cout<<depth(root)<<endl;
    }
    return 0;
}