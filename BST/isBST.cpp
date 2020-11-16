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

node* delete_in_bst(node* root, int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = delete_in_bst(root->left, data);
    }
    else if(data == root->data){
        
        //three cases
        
        //1. node with zero child (leaf node)
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        
        //2. node with one child
        if(root->left!=NULL && root->right==NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }

        //3. node with two child (can be root node)
        node *replace = root->right;
        while(replace->left!=NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = delete_in_bst(root->right, replace->data);
        return root;
    }
    else{
        root->right = delete_in_bst(root->right, data);
    }
}

bool isBST(node* root, int min = INT8_MIN, int max = INT8_MAX){
    if(root==NULL){
        return true;
    }    
    if(root->data >= min && root->data <= max && isBST(root->left, min, root->data) && isBST(root->right, root->data, max)){
        return true;
    }
    return false;
}


int main(){
    static int k = 1;
    while(k>0){
        int g;
        node*root=build();
        print_level_order(root);
        cout << endl;

        //check if this binary tree is a BST
        cout << isBST(root) << endl << "0 Matlab false and 1 Matlab true"<<endl;

        //testing
        cout << "enter the value of k: " << endl;
        cin >> g;
        k = g;
    }
    
    return 0;
}