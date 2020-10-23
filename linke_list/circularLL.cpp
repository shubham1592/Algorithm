#include <iostream>
using namespace std;

// Here I'll be implementing the concept of circular linked list in c++ suing the following functions
// 1. build() a linked list (input elements)
// 2. push() element ( (a)front (b)mid (c)end )
// 3. pop() element ( (a)front (b)mid (c)end )
// 4. printl() displays the linked list
// 5. merge() combines two seperately sorted linked lists into one single sorted linked list
// 6. And a lot of more functions that you can see in the following doc.
//Well it's not so diff from normal linked list so ill not be doing all of them tho. 

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


//To calculate the length of a circular Linked List........................................
int length(node *head){
    int count = 0;
    node*temp = head;
    if(head != NULL){
        while( temp->next != head){
            count++;
            temp = temp->next;
        }
    }
    return count;
}


//To insert a new element in the cirsular linked list.......................................
void insert(node*&head, int data){
    node* n = new node(data);
    node* temp = head;
    n->next=head;
    if(temp != NULL){
        while(temp->next != head){
            temp=temp->next;
        }
        temp->next = n;
    }
    else{
        n->next=n;
    }
    head = n;
    return;
}


//To print the circular linked list in an old fashioned way.................................
void printl(node*head){
    node* temp = head;
    while(temp->next != head){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<temp->data<<" -> "<<endl;
    return;
}


//To check if the node is present in the list or not.........................................
node* getnode(node*head, int data){
    node*temp = head;
    while(temp->next != head){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    if(temp->data == data){
        return temp;
    }
    return NULL;
}


//To delete a given node from the circular linked list.......................................
void deletenode(node*&head, int data){
    node* del = getnode(head, data);
    if(del == NULL){
        return;
    }
    if(head == del){
        head = head->next;
    }
    node*temp = head;
    while(temp->next != del){
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
}

//Driver function main() to call and implement all the functions used........................
int main(){
    node* head = NULL;
    insert(head, 10);
    insert(head, 23);
    insert(head, 14);
    insert(head, 74);
    insert(head, 15);
    cout<<"\n"<<length(head)<<endl;
    printl(head);
    deletenode(head, 15);
    printl(head);
    deletenode(head, 14);
    printl(head);
    deletenode(head, 10);
    printl(head);
}