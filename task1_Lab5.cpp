#include <iostream>
using namespace std;
// Node structure definition
struct Node 
{
    int data;      // data to store
    Node* next;    // pointer to the next node
};
// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int newData) 
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) 
    {
        last = last->next;
    }
    // link the new node at the end of the list
    last->next = newNode;
}
// Function to delete a node from the linked list by value
void deleteNode(Node** head, int key) 
{
    Node* temp = *head;
    Node* prev = NULL;
    // if the head node holds the key to be deleted
    if (temp != NULL && temp->data == key) 
    {
        *head = temp->next;
        delete temp;
        return;
    }
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
    // If the key was not present in the linked list
    if (temp == NULL) 
    {
        cout << "Value not found in the list." << endl;
        return;
    }
    // Unlink the node from the list
    prev->next = temp->next;
    // Free the memory of the node
    delete temp;
}
// Function to search for a value in the linked list
bool search(Node* head, int key) 
{
    Node* current = head;
    while (current != NULL) 
    {
        if (current->data == key) 
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
// Function to print the linked list
void printList(Node* node) 
{
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() 
{
    // Initialize the head as NULL (empty list)
    Node* head = NULL;
    int newData, deleteValue, searchValue;
    // Take 5 values as input to create the linked list
    for (int i = 0; i < 5; i++) 
    {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> newData;
        insertAtEnd(&head, newData);
    }
    // Print the linked list
    cout << "The linked list is: ";
    printList(head);
    // Perform deletion of a node
    cout << "Enter the value of the node to be deleted: ";
    cin >> deleteValue;
    deleteNode(&head, deleteValue);
    // Print the linked list after deletion
    cout << "The linked list after deletion is: ";
    printList(head);
    // Perform search for a value
    cout << "Enter the value to search in the list: ";
    cin >> searchValue;
    if (search(head, searchValue)) 
    {
        cout << "Value " << searchValue << " found in the list." << endl;
    } else 
    {
        cout << "Value " << searchValue << " not found in the list." << endl;
    }
    return 0;
}
