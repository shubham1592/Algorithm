#include <iostream>
using namespace std;

// Here I'll be implementing the concept of linked list in c++ suing the following functions
// 1. build() a linked list (input elements)
// 2. push() element ( (a)front (b)mid (c)end )
// 3. pop() element ( (a)front (b)mid (c)end )
// 4. printl() displays the linked list
// 5. merge() combines two seperately sorted linked lists into one single sorted linked list
// 6. And a lot of more functions that you can see in the following doc. 

//Defining a common class for any Linked List along with a constructor..............................................
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};


//To calculate the length of a Linked List..............................................
int length(node *head){
    int count = 0;
    while( head != NULL){
        count++;
        head = head->next;
    }
    return count;
}


//To add a new element in the linked list AT FRONT..............................................
void pushfront(node *&head, int d)
{
    node *n = new node(d);
    n->next = head;
    head = n;
    return;
}


//To add a new element in the Linked list AT THE END..............................................
void pushend(node *&head, int d){
    if(head == NULL){
        pushfront(head, d);
        return;
    }
    node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}


//To add a new element in the linked list AT MIDDLE (Position to be specified by the user)..............................................
void pushmid(node *&head, int d, int p){
    if(head == NULL || p == 0){
        pushfront(head, d);
        return;
    }
    if(p>length(head)){
        pushend(head, d);
        return;
    }
    int jump = 1;
    node *temp = head;
    while(jump <= p-1){
        temp = temp->next;
        jump++;
    }
    node *n = new node(d);
    n->next=temp->next;
    temp->next = n;
    return;
}


//To delete an element from the front.......................................................................
void deletefront(node*&head){
    if(head == NULL){
        return;
    }
    node*temp = head->next;
    delete head;
    head = temp;
    return;
}


//To delete an element from the end.........................................................................
void deletend(node*head){
    node*tempend = head;
    while(tempend!=NULL){
        tempend = tempend->next;
    }
    node*temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete tempend;
    temp->next=NULL;
    return;
}


// //To delete an element from middle...........................................................................
// void deletemid(node*&head, int p){
//     int jump = 1;
//     node *temp = head;
//     while (jump < p){
//         temp = temp->next;
//         jump++;
//     }
//     node *temp1 = head;
//     while (jump <= p){
//         temp1 = temp1->next;
//         jump++;
//     }
//     temp->next = temp1->next;
//     delete temp1;
// }


//To print/display the given Linked List......................................................
void printl(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout<<endl;
    return;
}


//To take input directly from the terminal given by the user........................................
node* take_input(){
    int d;
    cin>>d;
    node*head = NULL;
    while(d!=-1){
        pushend(head,d);
        cin>>d;
    }
    return head;
}


//To make cout<< work naturally for a linked list as well (operator << overloading).................
ostream& operator << (ostream&os, node*head){
    printl(head);
    return os;
}


//To make cin>> work naturally for a linked list as well (operator >> overloading).................
istream& operator >> (istream&is, node*&head){
    head = take_input();
    return is;
}


//To merge two given sorted linked lists and combine into a single one..............................
node* merge(node* a, node* b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    node* c;
    if(a->data<b->data){
        c=a;
        c->next=merge(a->next, b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}



//Driver program to run all the linked list functions..............................................
int main()
{
    // node *head = NULL;
    // pushfront(head, 5);
    // pushfront(head, 10);
    // pushfront(head, 2);
    // pushfront(head, 14);
    // cout<<length(head)<<endl;
    // printl(head);
    // pushmid(head, 21, 3);
    // printl(head);
    // pushmid(head, 19, 1);
    // printl(head);
    // pushend(head, 30);
    // cout<<head;
    // deletend(head);
    // cout<<head;
    // deletefront(head);
    // cout<<head;
    // deletemid(head, 2);
    //node*head = take_input();
    // node *head = NULL;
    // pushfront(head, 5);
    // pushfront(head, 10);
    // pushfront(head, 2);
    // pushfront(head, 14);
    // cout<<length(head)<<endl;
    // printl(head);
    // pushmid(head, 21, 3);
    // printl(head);
    // pushmid(head, 19, 1);
    // printl(head);
    // pushend(head, 30);
    // cout<<head;
    // deletend(head);
    // cout<<head;
    // deletefront(head);
    // cout<<head;
    // deletemid(head, 2);
    //node*head = take_input();
    cout<<endl;
    node*head1;
    node*head2;
    cin>>head1;
    cin>>head2;
    cout<<merge(head1, head2)<<endl;
    
    return 0;    
}