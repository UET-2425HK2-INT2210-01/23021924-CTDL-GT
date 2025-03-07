#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear; 
public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    int n, value;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }
    
    q.display();

    return 0;
}

//  MÃ GIẢ
// BẮT ĐẦU

//     Định nghĩa cấu trúc Node (dữ liệu, con trỏ next)

//     Định nghĩa lớp Queue
//         - Thuộc tính: front, rear
//         - Hàm tạo: Khởi tạo front và rear = NULL
//         - Hàm isEmpty(): Kiểm tra hàng đợi rỗng
//         - Hàm enqueue(value): Thêm phần tử vào cuối hàng đợi
//         - Hàm dequeue(): Xóa phần tử đầu hàng đợi
//         - Hàm display(): Hiển thị danh sách liên kết
//         - Hàm hủy: Xóa toàn bộ hàng đợi khi kết thúc

//     Hàm main()
//         - Nhập số lượng phần tử
//         - Nhập các giá trị và thêm vào hàng đợi
//         - Hiển thị danh sách liên kết

// KẾT THÚC

// Độ phức tạp:
// O(n) đối với hàm display khi duyệt liên KẾT
// O(1) đối với hàm enqueue, dequeue
// Độ phức tạp trung bình O(n).