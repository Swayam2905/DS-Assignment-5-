#include <iostream>

struct Node {
    int data;
    Node* next;
    // Constructor now uses NULL for backward compatibility
    Node(int val) : data(val), next(NULL) {}
};

// Helper function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;
        // Reverse the current node's pointer
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    // The new head is the last node we processed (prev)
    head = prev;
    return head;
}

int main() {
    // Create the sample linked list: 1->2->3->4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    std::cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}

