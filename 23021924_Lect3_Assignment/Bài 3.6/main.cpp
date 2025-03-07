#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }
    
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << endl;
        delete temp;
    }
    
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements:" << endl;
        while (current) {
            cout << current->data << "  ";
            current = current->next;
        }
        cout << "None" << endl;
    }
};

int main() {
    Stack stack;
    string operation;
    
    while (true) {
        cout << "\nChoose an operation: push <value>, pop, peek, display, exit" << endl;
        cout << "Enter operation: ";
        cin >> operation;
        
        if (operation == "push") {
            int value;
            cin >> value;
            stack.push(value);
        } else if (operation == "pop") {
            stack.pop();
        } else if (operation == "peek") {
            stack.peek();
        } else if (operation == "display") {
            stack.display();
        } else if (operation == "exit") {
            cout << "Final stack state:" << endl;
            stack.display();
            break;
        } else {
            cout << "Invalid operation. Try again." << endl;
        }
    }
    return 0;
}

// MÃ GIẢ:
// Lớp Node:
//     Thuộc tính:
//         - data: lưu giá trị của nút
//         - next: con trỏ trỏ đến nút tiếp theo

//     Hàm khởi tạo(Node mới, giá trị):
//         - Gán data = giá trị
//         - Gán next = null
// Lớp Stack:
//     Thuộc tính:
//         - top: con trỏ trỏ đến phần tử đầu ngăn xếp

//     Hàm khởi tạo():
//         - Gán top = null

//     Hàm push(giá trị):
//         - Tạo một nút mới với giá trị
//         - Gán next của nút mới = top
//         - Cập nhật top = nút mới

//     Hàm pop():
//         - Nếu ngăn xếp rỗng:
//             - In "Ngăn xếp trống! Không thể pop."
//             - Thoát
//         - Lưu giá trị của top
//         - Cập nhật top = phần tử tiếp theo
//         - Xóa phần tử cũ
//         - In "Đã xóa:", giá trị đã xóa

//     Hàm peek():
//         - Nếu ngăn xếp rỗng:
//             - In "Ngăn xếp trống!"
//             - Thoát
//         - In "Phần tử đầu ngăn xếp:", giá trị của top

//     Hàm isEmpty():
//         - Nếu top = null:
//             - Trả về true
//         - Ngược lại, trả về false

//     Hàm display():
//         - Nếu ngăn xếp rỗng:
//             - In "Ngăn xếp trống!"
//             - Thoát
//         - Duyệt từ top đến null, in từng phần tử theo thứ tự
// Hàm main():
//     Tạo một ngăn xếp mới
//     Lặp vô hạn:
//         - Hiển thị lựa chọn: "push <giá trị>, pop, peek, display, exit"
//         - Nhập thao tác từ người dùng

//         Nếu thao tác là "push <giá trị>":
//             - Thêm phần tử vào ngăn xếp

//         Nếu thao tác là "pop":
//             - Gọi hàm pop()

//         Nếu thao tác là "peek":
//             - Gọi hàm peek()

//         Nếu thao tác là "display":
//             - Gọi hàm display()

//         Nếu thao tác là "exit":
//             - In trạng thái cuối cùng của ngăn xếp
//             - Thoát vòng lặp

//         Nếu thao tác không hợp lệ:
//             - In "Lệnh không hợp lệ! Vui lòng nhập lại."

// ĐÁNH GIÁ ĐỘ PHỨC TẠP
// độ phức tạp O(1) đối với các lệnh push, pop, peek.
// độ phức tạp O(n) đối với lệnh display, exit khi phải duyệt để in lại danh sách
// Độ phức tạp trung bình O(n).