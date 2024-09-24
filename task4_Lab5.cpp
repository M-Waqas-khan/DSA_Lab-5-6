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
    newNode->next = NULL;
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        Node* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// Find the middle of the linked list using slow and fast pointers
void findMiddle(Node* head) 
{
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;         // Move slow by 1
        fast = fast->next->next;   // Move fast by 2
    }
    cout << "Middle element: " << slow->data << endl;
}
// Print the linked list
void printList(Node* node) 
{
    while (node != NULL) 
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = NULL;
    int n, newData;
    // Input the number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;
    // Insert nodes
    for (int i = 0; i < n; i++) {
        cout << "Enter value for "<<i<<" node: ";
        cin >> newData;
        insertAtEnd(&head, newData);
    }
    // Print the list
    cout << "The linked list is: ";
    printList(head);
    // Find and print the middle element
    cout<< "The Middle Element is: ";
    findMiddle(head);
    return 0;
}
