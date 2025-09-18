#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to find the middle of the linked list
Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    // Move fast pointer by two and slow pointer by one
    // When fast pointer reaches the end, slow pointer will be at the middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    // Create the sample linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* middleNode = findMiddle(head);

    if (middleNode != NULL) {
        std::cout << "The middle of the linked list is: " << middleNode->data << std::endl;
    } else {
        std::cout << "The list is empty." << std::endl;
    }

    return 0;
}

