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

node* build(){
    int d;
    cin >> d;
    if(d==-1){
        return NULL;
    }
    node *root = new node(d);
    root->left = build();
    root->right = build();
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

int search(node*root, int key, int level){
    if(root == NULL){
        return -1;
    }
    if(root->data == key){
        return level;
    }
    int left = search(root->left, key, level + 1);
    if(left != -1){
        return left;
    }
    return search(root->right, key, level + 1);
}

int shortest_distance(node*root, int a, int b){
    node *lcanode = lca(root, a, b);
    int p1 = search(lcanode, a, 0);
    int p2 = search(lcanode, b, 0);
    return p1 + p2;
}

int main(){
    node*root=build();
    int a,b;
    cin >> a >> b;
    print_level_order(root);
    cout << endl;
    cout << "Shortest distance between " << a << " and " << b << " is : ";
    cout << shortest_distance(root, a, b);
    
    return 0;
}