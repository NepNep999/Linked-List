#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(char val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Data: " << temp->data << " -> "<<&temp->data<<endl;
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void sum() {
        cout << "Sum function is not applicable for characters." << endl;
    }

    void count() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        cout << "Total length of your linked list: " << count << endl;
    }

    void insertNew(char targetNode, char newData) {
        Node* temp = head;
        while (temp != NULL && temp->data != targetNode) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Node Unknown" << endl;
            return;
        }
        Node* newNode = new Node(newData);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << newData << " after " << targetNode << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    int n;
    char value, targetNode, newData;

    cout << "Enter the number of elements you want: ";
    cin >> n;

    for (int s = 0; s < n; s++) {
        cout << "Enter Character number " << s + 1 << ": ";
        cin >> value;
        list.insert(value);
    }
    cout << endl << "Linked List:" << endl;
    list.display();
    cout << endl;
    list.sum();
    cout << endl;
    cout << "Choose the node you want to insert after: ";
    cin >> targetNode;
    cout << "Enter the new data: ";
    cin >> newData;
    cout << endl;
    list.insertNew(targetNode, newData);
    list.count();
    cout << "Updated List: " << endl;
    list.display();

    return 0;
}
