#include <iostream>
using namespace std;

// Here I'll be implementing the concept of linked list in c++ suing the following functions
// 1. build() a linked list (input elements)
// 2. push() element ( (a)front (b)mid (c)end )
// 3. pop() element ( (a)front (b)mid (c)end )
// 4. printl() displays the linked list
// 5. merge() combines two seperately sorted linked lists into one single sorted linked list


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


//To print/display the given Linked List..............................................
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


//Driver program to run all the linked list functions..............................................
int main()
{
    node *head = NULL;
    pushfront(head, 5);
    pushfront(head, 10);
    pushfront(head, 2);
    pushfront(head, 14);
    cout<<length(head)<<endl;
    printl(head);
    pushmid(head, 21, 3);
    printl(head);
    pushmid(head, 19, 1);
    printl(head);
    pushend(head, 30);
    printl(head);

    return 0;    
}