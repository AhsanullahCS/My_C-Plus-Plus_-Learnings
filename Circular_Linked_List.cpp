#include<iostream>
using namespace std;

struct node 
{
    int data;
    node *next;
};

node *head = NULL; 
node *tail = NULL;

void InsertAtEnd(int n) 
{
    node *newnode = new node;
    newnode->data = n;

    if (head == NULL) 
    {
        head = tail = newnode;
        newnode -> next = head;
    } 
    else 
    {
        tail -> next = newnode;
        newnode -> next = head;
        tail = newnode;
    }
}

void InsertionAtStart(int n)
{
    node *newnode = new node;
    newnode -> data = n;

    if(head == NULL)
    {
        head = tail = newnode;
        newnode -> next = head;
    }
    else
    {
        newnode -> next = head;
        head = newnode;
        tail -> next = head;
    }
}

void DelAtStart()
{
    if(head == NULL)
    {
        cout<<"list empty";
        return;
    }
    if(head == tail)
    {
        delete head;
        head = tail = NULL;
        return;
    }
    node *temp = head;
    head = head -> next; 
    tail -> next = head;
    delete temp;
}

void DelAtEnd()
{
    if(head == NULL)
    {
        cout<<"list empty";
        return;
    }
    if(head == tail)
    {
        delete head;
        head = tail = NULL;
        return;
    }

    node *temp = head;

    while(temp -> next  != tail)
    {
        temp  = temp -> next;
    }

    delete tail;
    tail = temp;
    tail -> next = head;
}

void Print()
{
    if (head == NULL)
    {
        cout<<"NOTHING TO PRINT ";
        return;
    }
    node *temp = head;
    do
    {
        cout << temp->data <<" ";
        temp = temp->next;
    } 
    while(temp != head); 
}

int main()
{
    InsertAtEnd(10);
    InsertAtEnd(20);
    InsertAtEnd(30);
    InsertAtEnd(40);
    InsertAtEnd(50);
    InsertionAtStart(60);
    InsertionAtStart(70);
    InsertionAtStart(80);
    Print();

return 0;
}