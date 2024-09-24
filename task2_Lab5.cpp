#include <iostream>
using namespace std;
struct Node 
{
    int data;      // Data to store in the node
    Node* next;    // Pointer to the next node
};
// Insert node at the end of the linked list
void insertAtEnd(Node** head, int newData) 
{
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newData;  // Assign the data
    newNode->next = NULL;     // Set next pointer to NULL (end of list)
    // If the list is empty, set head to the new node
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    // Otherwise, traverse to the end and add the new node
    else 
    {
        Node* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;  // Move to the last node
        }
        temp->next = newNode;   // Link the new node at the end
    }
}
// Reverse the linked list
void reverseList(Node** head) 
{
    Node *prev = NULL, *current = *head, *next = NULL;
    // Traverse through the list and reverse the links
    while (current != NULL) 
    {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev and current one step forward
        current = next;
    }
    *head = prev;  // Update the head to the last node (new head)
}
// Print the linked list
void printList(Node* node) 
{
    while (node != NULL) 
    {
        cout << node->data << " -> ";  // Print current node's data
        node = node->next;  // Move to the next node
    }
    cout << "NULL" << endl;  // End of list
}
int main() 
{
    Node* head = NULL;  // Initialize head as NULL (empty list)
    int newData;
    // Input 5 nodes from the user
    for (int i = 0; i < 5; i++) 
    {
        cin >> newData;            // Input data for the new node
        insertAtEnd(&head, newData); // Insert node at the end of the list
    }
    // Print the original list
    cout << " The linked list is: ";
    printList(head);
    // Reverse the list
    reverseList(&head);
    // Print the reversed list
    cout << "The reversed linkrd list is: ";
    printList(head);
    return 0;
}
