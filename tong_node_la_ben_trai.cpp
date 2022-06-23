#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
long long n, sum = 0 ;
void DFS(Node *root){
    if(root->left != NULL ){
        if(root->left->left == NULL && root->left->right == NULL) 
            sum += root->left->data;
        else DFS(root->left);
    }
    if(root->right != NULL) DFS(root->right);
}
int main(){
    int t;
    cin>>t;
    while(t--){
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
        sum = 0;
        DFS(root);
        cout<<sum<<endl;
    }

    return 0;
}