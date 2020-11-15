#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* insertintoBST(node* root, int data){
    if(root==NULL){
        return new node(data);
    }
    else if(data<=root->data){
        root->left = insertintoBST(root->left, data);
    }
    else{
        root->right = insertintoBST(root->right, data);
    }
}

node* build(){
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1){
        root = insertintoBST(root, d);
        cin >> d;
    }
    return root;
}

void preorder_print(node*root){
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder_print(root->left);
    preorder_print(root->right);
}

void inorder_print(node*root){
    if (root == NULL)
    {
        return;
    }
    inorder_print(root->left);
    cout << root->data << " ";
    inorder_print(root->right);
}

void postorder_print(node*root){
    if (root == NULL)
    {
        return;
    }
    postorder_print(root->left);
    postorder_print(root->right);
    cout << root->data << " ";
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

void print_kth_level(node*root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout << root->data << " ";
        return;
    }
    print_kth_level(root->left, k-1);
    print_kth_level(root->right, k-1);
    return;
}

void print_level_order(node*root){
    int h = height(root);
    for (int i = 1; i <= h; i++){
        print_kth_level(root, i);
        cout << endl;
    }
    return;
}

node* lca(node*root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    if(root->data == a || root->data == b){
        return root;
    }
    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);
    if(rightans != NULL && leftans != NULL){
        return root;
    }
    if(leftans != NULL){
        return leftans;
    }
    return rightans;
}

bool search(node*root, int data){
    if(root==NULL){
        return false;
    }
    if(data==root->data){
        return true;
    }
    if(data<=root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
    
}


int main(){
    node*root=build();
    print_level_order(root);
    cout << endl
         << search(root, 25);

    return 0;
}