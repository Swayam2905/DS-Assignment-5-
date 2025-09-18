#include <iostream>

// Define the structure for a node
struct Node {
    int data;
    Node* next;
    // Constructor now uses NULL for backward compatibility
    Node(int val) : data(val), next(NULL) {}
};

// Helper function to print the list
void printList(Node* head) {
    if (!head) {
        std::cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Function to count and delete all occurrences of a key
void countAndDeleteOccurrences(Node*& head, int key) {
    int count = 0;
    Node* temp = head;

    // First, count the occurrences
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    std::cout << "Count: " << count << std::endl;

    // Now, delete the nodes
    // Handle cases where the head node itself needs to be deleted
    while (head != NULL && head->data == key) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }

    // Delete occurrences from the rest of the list
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
        } else {
            current = current->next;
        }
    }
}

int main() {
    // Create the sample linked list: 1->2->1->2->1->3->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);
    
    int key = 1;

    std::cout << "Original Linked List: ";
    printList(head);

    countAndDeleteOccurrences(head, key);

    std::cout << "Updated Linked List: ";
    printList(head);

    return 0;
}