#include <iostream>
using namespace std;
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
void reverseList(Node** head)
{
  Node* prev = NULL;
  Node* current = *head;
  Node* next = NULL;
  while(current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    *head = prev;
  }
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
        insertAtEnd(&head, value);
    }
    cout << " Before reversing Linked list is: ";
    printList(head);

    reverseList(&head);
    printList(head);
    return 0;
}