#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Stack {
public:
    Node* top;
    
    Stack() : top(nullptr) {}
    
    void push(int x) {
        Node* newNode = new Node(x);
        if (top != nullptr) {
            newNode->next = top;
            top->prev = newNode;
        }
        top = newNode;
    }
    
    void pop() {
        if (top == nullptr) return;
        Node* temp = top;
        top = top->next;
        if (top != nullptr) top->prev = nullptr;
        delete temp;
    }
    
    void print() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Stack stack;
    
    for (int i = 0; i < n; ++i) {
        string command;
        int x;
        cin >> command;
        if (command == "push") {
            cin >> x;
            stack.push(x);
        } else if (command == "pop") {
            stack.pop();
        }
    }
    
    stack.print();
    return 0;
}
