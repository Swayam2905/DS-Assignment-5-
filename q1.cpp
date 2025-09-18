#include <iostream>

struct Node {
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    // (a) Insertion at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        std::cout << val << " inserted at the beginning.\n";
    }

    // (b) Insertion at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        std::cout << val << " inserted at the end.\n";
    }

    // (c) Insertion after a specific node value
    void insertAfterNode(int targetVal, int newVal) {
        Node* temp = head;
        while (temp != NULL && temp->data != targetVal) {
            temp = temp->next;
        }

        if (temp == NULL) {
            std::cout << "Node with value " << targetVal << " not found.\n";
            return;
        }

        Node* newNode = new Node(newVal);
        newNode->next = temp->next;
        temp->next = newNode;
        std::cout << newVal << " inserted after " << targetVal << ".\n";
    }
    
    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        std::cout << temp->data << " deleted from the beginning.\n";
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == NULL) {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (head->next == NULL) { // Only one node
            delete head;
            head = NULL;
            std::cout << "The only node has been deleted.\n";
            return;
        }
        Node* second_last = head;
        while (second_last->next->next != NULL) {
            second_last = second_last->next;
        }
        Node* nodeToDelete = second_last->next;
        std::cout << nodeToDelete->data << " deleted from the end.\n";
        delete nodeToDelete;
        second_last->next = NULL;
    }

    // (f) Deletion of a specific node
    void deleteNode(int val) {
        if (head == NULL) {
            std::cout << "List is empty.\n";
            return;
        }
        
        Node* temp = head;
        // If head node itself holds the key to be deleted
        if (temp != NULL && temp->data == val) {
            head = temp->next;
            delete temp;
            std::cout << val << " deleted from the list.\n";
            return;
        }

        Node* prev = NULL;
        while (temp != NULL && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            std::cout << "Node with value " << val << " not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        std::cout << val << " deleted from the list.\n";
    }

    // (g) Search for a node and display its position
    void searchNode(int val) {
        if (head == NULL) {
            std::cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        int position = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                std::cout << "Node " << val << " found at position " << position << ".\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        std::cout << "Node with value " << val << " not found in the list.\n";
    }

    // (h) Display all the node values
    void display() {
        if (head == NULL) {
            std::cout << "The list is empty.\n";
            return;
        }
        Node* temp = head;
        std::cout << "Linked List: HEAD -> ";
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;

    while (true) {
        std::cout << "\n--- Singly Linked List Menu ---\n";
        std::cout << "1. Insert at Beginning\n";
        std::cout << "2. Insert at End\n";
        std::cout << "3. Insert After a Node\n";
        std::cout << "4. Delete from Beginning\n";
        std::cout << "5. Delete from End\n";
        std::cout << "6. Delete a Specific Node\n";
        std::cout << "7. Search for a Node\n";
        std::cout << "8. Display List\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                std::cout << "Enter the value of the node to insert after: ";
                std::cin >> target;
                std::cout << "Enter the new value to insert: ";
                std::cin >> value;
                list.insertAfterNode(target, value);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                std::cout << "Enter value of the node to delete: ";
                std::cin >> value;
                list.deleteNode(value);
                break;
            case 7:
                std::cout << "Enter value to search for: ";
                std::cin >> value;
                list.searchNode(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
