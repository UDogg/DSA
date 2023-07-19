/*
To traverse a linked list in C++,
you can use a simple while loop to iterate 
through each node of the list. Here's a basic implementation:
*/
#include <iostream>

// Define the structure for the linked list node
struct Node {
    int data;
    Node* next;
};

// Function to traverse and print the linked list
void traverseLinkedList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int main() {
    // Creating a sample linked list with 4 nodes
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Traversing and printing the linked list
    traverseLinkedList(head);

    // Don't forget to free memory allocated for nodes (not shown in this basic example)
    return 0;
}
