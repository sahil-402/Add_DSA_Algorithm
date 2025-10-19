#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    // Insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at beginning
    void insertBegin(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Delete by value
    void deleteValue(int val) {
        if (!head) return;

        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Search by value
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Floyd’s Cycle Detection
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// Merge two sorted linked lists
Node* mergeTwoLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Reverse linked list in groups of k
Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    // Check if we have k nodes
    Node* temp = head;
    for (int i = 0; i < k && temp; i++)
        temp = temp->next;
    if (!temp && count < k)
        return head;

    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next)
        head->next = reverseKGroup(next, k);

    return prev;
}

// Main function for demonstration
int main() {
    LinkedList list;

    cout << "--- Insert Elements ---\n";
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertBegin(5);
    list.display();

    cout << "\n--- Delete Element (20) ---\n";
    list.deleteValue(20);
    list.display();

    cout << "\n--- Search Element (30) ---\n";
    cout << (list.search(30) ? "Found\n" : "Not Found\n");

    cout << "\n--- Reverse Linked List ---\n";
    list.reverse();
    list.display();

    cout << "\n--- Check Cycle ---\n";
    cout << (hasCycle(list.head) ? "Cycle Found\n" : "No Cycle\n");

    cout << "\n--- Merge Two Sorted Lists ---\n";
    LinkedList list1, list2;
    list1.insertEnd(1);
    list1.insertEnd(3);
    list1.insertEnd(5);
    list2.insertEnd(2);
    list2.insertEnd(4);
    list2.insertEnd(6);
    Node* mergedHead = mergeTwoLists(list1.head, list2.head);
    while (mergedHead) {
        cout << mergedHead->data << " -> ";
        mergedHead = mergedHead->next;
    }
    cout << "NULL\n";

    cout << "\n--- Reverse in Groups of 2 ---\n";
    LinkedList groupList;
    for (int i = 1; i <= 6; i++) groupList.insertEnd(i);
    groupList.head = reverseKGroup(groupList.head, 2);
    groupList.display();

    return 0;
}
