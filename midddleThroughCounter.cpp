#include <iostream>
using namespace std;
int counter;
struct Node
{
    int data;
    Node* next; 
};
void insertAtEnd(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next  = NULL;
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
Node* last = *head;
while(last->next != NULL)
{
    last = last->next;
}
    last->next = newNode;
}
void findMiddle(Node* head)
{
    if(head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }
    Node* slow = head;
    Node* fast= head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "The middle Element is: " << slow->data << endl;
}
void middle(Node* node, int counter)
{
  int count1 = counter/2;
for (int i=1; i<=count1; i++)
{
   node = node -> next;
}
cout << "Middle node Value is: " << node->data << endl;
}
void printList(Node* node)
{
   cout << " linked list elements: ";
   while( node != NULL)
   {
      cout  << node->data << " -> ";
      node = node -> next;
   }
   cout << "NULL" <<endl;
}
int main()
{
    Node* head = NULL;
    int n, value;
    cout<<" How many values do yo want to insertr in this list: ";
    cin>>n;
    for( int i=0; i<n; i++)
    {
        cout << " Enter value "<< i+1 <<" : ";
        cin >> value;
        counter++;
        insertAtEnd(&head, value);
    }
    printList(head);
    findMiddle(head);
    middle(head,counter);
    return 0;
}