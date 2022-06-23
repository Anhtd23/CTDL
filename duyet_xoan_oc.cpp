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
vector<int> a;
void duyetXoanOc(Node* root){
    queue<Node*> q;
    q.push(root);
    int k = 1;
    cout<<root->data<<" ";
    while (!q.empty())
    {
        int s = q.size();
        for(int i = 0 ; i < s ; i++){
            Node* tmp = q.front();
            q.pop();
            if(tmp->left != NULL ){
                q.push(tmp->left);
                a.push_back(tmp->left->data);
            }
            if(tmp->right != NULL){
                q.push(tmp->right);
                a.push_back(tmp->right->data);
            }
        }
        if(a.size() != 0){
            if(k % 2 == 0 ){
                for(int i = a.size()- 1 ; i >= 0 ; i--){
                    cout<<a[i]<<" ";
                }
            }
            else for(int i = 0  ; i < a.size() ; i++) cout<<a[i]<<" ";
        }
        a.clear();
        k++;
    }
    cout<<endl;   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
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
        duyetXoanOc(root);
    }

    return 0;
}