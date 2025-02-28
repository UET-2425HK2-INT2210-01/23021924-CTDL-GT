#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;
public:
    Queue() : head(nullptr), tail(nullptr) {}
    
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }
    
    void printQueue() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    ~Queue() {
        while (head) {
            dequeue();
        }
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    Queue q;
    string command;
    
    for (int i = 0; i < n; i++) {
        getline(cin, command);
        stringstream ss(command);
        string operation;
        ss >> operation;
        
        if (operation == "enqueue") {
            int value;
            ss >> value;
            q.enqueue(value);
        } else if (operation == "dequeue") {
            q.dequeue();
        }
    }
    
    q.printQueue();
    
    return 0;
}
