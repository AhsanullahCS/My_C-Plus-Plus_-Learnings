#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *start = NULL;
node *last  = NULL;

void insertAtEnd(int value)
{
    node *newnode = new node;
    newnode -> data = value;
    newnode ->prev = NULL;
    newnode->next = NULL;

    if(start == NULL)
    {
        start = last = newnode;
        newnode -> next = start;
        newnode -> prev = last;
        return;
    }
    else
    {
    newnode -> prev = last;
    newnode -> next = start;

    last -> next = newnode;
    start->prev = newnode;

    last = newnode;
    
    }
}
void insertAtStart(int value)
{
    node *newnode = new node;
    newnode -> data = value;
    newnode ->next  = NULL;
    newnode ->prev  = NULL;

    if(start == NULL)
    {
        start = last = newnode;
        last -> next = newnode;
        start -> prev = newnode;
    }
    else
    {
        newnode -> next = start;
        newnode -> prev = last;

        start -> prev = newnode;
        last -> next = newnode;
        
        start = newnode;
    }
}
void insertAtSpecificPosition(int value , int position)
{
    if(position < 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(position == 1)
    {
        insertAtStart(value);
        return;
    }
    node *temp = start;
    int count = 1;
    while(count < position -1 && temp->next != start)
    {
        temp = temp ->next;
    }

    if(temp == last)
    {
        insertAtEnd(value);
        return;
    }

    if(count != position -1)
    {
        cout<<"POSITION IS OUT OF RANGE";
        return;
    }

    node *newnode = new node;
    newnode -> data = value;

    newnode -> next = temp -> next;
    newnode -> prev = temp;

    temp -> next -> prev = newnode;
    temp -> next = newnode;
}
void DelAtStart()
{
    if(start == NULL)
    {
        cout<<"EMPTY NOTHING TO DELETE";
        return;
    }
    node *temp = start; 
    if(start == last)
    {
        start = last = NULL;
    }
    else
    {
        start = start -> next;
        start -> prev = last;
        last -> next = start;
    }
    delete temp;
}
void delAtEnd()
{
    if(start == NULL)
    {
        cout<<"EMPTY NOTHING TO DELETE";
        return;
    }
    node *temp = last; 
    if(start == last)
    {
        start = last = NULL;
    }
    else
    {
        last = last -> prev;
        last -> next = start;
        start -> prev = last;
    }
    delete temp;
}

void delAtSpecificPosition(int pos)
{
    if(start == NULL)
    {
        cout<<"EMPTY NOTHING TO DELETE";
        return;
    }

    if(pos == 1)
    { 
        DelAtStart();
    }
    node *temp = start;
    int count = 1;

    while(count < pos && temp->next != start)
    {
        temp = temp->next;
        count++;
    }

    if(count != pos)
    {
        cout << "POSITION OUT OF RANGE";
        return;
    }
    if(temp == last)
    {
        delAtEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

void print()
{
    if(start == NULL)
    {
        cout<<"EMPTY NOTHING TO PRINT";
        return;
    }
    node *temp = start;
    do
    {

        cout<<temp->data<<" ";
        temp = temp -> next;
        if(temp == start)
          break;
    }while(temp != NULL );
}

int main()
{
    insertAtEnd(20);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(20);
    insertAtStart(10);
    insertAtSpecificPosition(50,2);

    DelAtStart();
    delAtEnd();
    delAtSpecificPosition(2);

    print();
return 0;
}