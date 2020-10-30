#include<iostream>
#include<queue>
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

void bfs(node*root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *f = q.front();
        cout << f->data << " ";
        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}

int dia(node*root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = dia(root->left);
    int op3 = dia(root->right);
    return max(op1, max(op2, op3));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CREATING A TREE FROM THE GIVEN PREORDER AND INORDER TRAVERSED ARRAY

node* createTree(int *in, int *pre, int s, int e){
    static int i = 0;
    if(s>e){
        return NULL;
    }
    node *root = new node(pre[i]);
    int idx = -1;
    for (int j = s; s < e; j++){
        if(in[j]==pre[i]){
            idx = j;
            break;
        }
    }
    i++;
    root->left = createTree(in, pre, s, idx - 1);
    root->right = createTree(in, pre, idx + 1, e);
    return root;
}

int main(){
    /*
    node*root=build();
    cout << endl
         << "Height of the tree: " << height(root);
    cout << endl
         <<"Level order print: "<<endl;
    print_level_order(root);
    cout << endl
         << "BFS traversal:  ";
    bfs(root);
    cout << endl
         << "Diameter of the tree:  " << dia(root);
    return 0;
    */

   int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n = 8;

    node*root = createTree(in,pre,0,7);
    bfs(root);
}