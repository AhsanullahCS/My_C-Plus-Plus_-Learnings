#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
 
node *head = NULL;

//insertion 
void insert(int n)
{                 //   struct name
   node *newnode  = new node;
   newnode ->data = n;
   newnode ->next = head;
   head = newnode;
}

void DEL1stNode()
{
    //check the single linked list is empty or not
    if(head == NULL)
    {
        cout<<"linked list is empty";
        return;
    }
    // if not then we have to create the temp pointer to 
    node *temp = head;
    head = head -> next; // now thw head pointer point the 2nd node
    delete temp;
}


void DELLastNode()
{//1st check the list is empty
    if(head == NULL)
    {
        cout<<"list is empty";
        return; // ot avoid further execution 
    }
    // separate code for deletion a single node and when more then 1 nodes
    //for 1 node 
    if(head -> next == NULL)// head pointer jis node ko point kar raha ha us ka next ma null store ha   
    {
        delete head ;//This means: "Free the memory of the node that head is pointing to."So the whole first node (with its data and its next) gets removed from memory.
        head  = NULL;//there are no nodes left in the list.
        return;
    }
// when more then 1 nodes then how to delete the last node
//assess 2nd last nodes for this you have to traversed the nodes

node *temp = head;
while(temp -> next -> next != NULL)/* temp -> next mean checking own node itself that if he has then address of any next node and temp ->next ->next mean check the address of next node 5 to 4*/
{
    temp = temp -> next;
}
delete temp -> next;//🧹 “Free the memory of the node [1] from the heap.”But ⚠️ your pointer temp->next still contains the old garbage address
temp -> next = NULL;  // thats why ew assign it null 
}
//REMOVE POINT FROM SPECIFIC POSITION
void specificPosition(int position)
{// check that the list is empty or not 
    if(head == NULL)
    {
        cout<<"LIST IS EMPTY";
    }
    node *temp = head;
    //it is possible that  the user say delete 1st node 
    if(position == 1)
    {
        head = temp -> next;//It moves the head pointer from Box1 to Box2.
        delete temp;
        return;
    }
    //when we have to delete the node 3 then we have to access the node 2 mean previous node 
    //                              2     
    for(int i=1;  temp != NULL && i<position-1;  i++)
    {
        temp = temp -> next;
    }
                       //30 → NULL mean 2nd last node is pointing that i have the address of last node which is null  
    if(temp == NULL || temp -> next == NULL)
    {
        cout<<"Position "<<position<<" doesnot exist"<<endl;
        return;
    }//  pointer
    node *next  =    temp ->next->next;//this mean we are accessing the node that is after the node we want to delete //**temp ->next->next;
    delete temp -> next;//  we delete the node next because we access the node before the original node 
    temp -> next = next; //temp -> next = next; **/*///*/-> next this next mean the next that is save in *next pointer
}

int Search(int n)
{// to search we create temp pointer
    node *temp  = head;
    int pos = 1;
    while(temp != NULL)
    {
        if(temp -> data == n)
        {
            return pos;
        }
        temp = temp -> next;
        pos++;
    }
    return -1;
} 

void print()
{
    node *temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<"  "<<endl;
        temp = temp->next;
    }
}

int main()
{
    insert(1);
    
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    DEL1stNode();
    DELLastNode();
    specificPosition(3);
     
    int pos = Search(4);
    if(pos != -1)
        cout << "Element found at position: " << pos << endl;
    else
        cout << "Element not found!" << endl;
    print();

    
return 0;
}