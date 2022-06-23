#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data, l , r;
    Node *left, *right;
    Node(int d, int x, int y){
        l = x;r = y;
        data = d;
        left = right = NULL;
    }
};
int searchA(int a[], int x, int y, int k){
    for(int i = x ; i <= y ; i++){
        if( a[i] == k) return i;
    }
    return -1;
}
void duyetSau(Node *root, int order[]){
    if(root->left != NULL) duyetSau(root->left, order);
    if(root->right != NULL) duyetSau(root->right, order);
    cout<<order[root->data]<<" ";
}
void makeTree(int in[], int order[], int n){
    queue<Node*> q;
    Node* root = new Node(0, 0, n-1);
    q.push(root);
    int k = 1;
    while (!q.empty())
    {
        int s = q.size();
        //cout<<"size : "<<s<<endl; 
        for(int i = 0 ; i < s ; i++){
            Node* tmp = q.front();
            q.pop();
            //cout<<tmp->data<<" ";
            if(tmp->l < tmp->r){
                int h = searchA(in, tmp->l,tmp-> r,order[tmp->data]);
                //cout<<"h : "<<h<<endl;
                if(h - 1 >= tmp->l){
                    Node *tmp1 = new Node(k++, tmp->l, h-1);
                    tmp -> left = tmp1;
                    if(h-1 > tmp->l) q.push(tmp1);
                }
                if(h + 1 <= tmp->r){
                    Node *tmp2 = new Node(k++, h+1, tmp->r);
                    tmp->right = tmp2;
                    if(h+1 < tmp->r) q.push(tmp2);
                }
            }
        }
        //cout<<endl;
    }
    duyetSau(root, order);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int in[n], order[n];
        for(int i = 0 ; i < n ; i++) cin>>in[i];  
        for(int i = 0 ; i < n ; i++) cin>>order[i];
        makeTree(in, order, n);
        cout<<endl;
    }
    return 0;    
}