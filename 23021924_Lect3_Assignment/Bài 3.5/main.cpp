#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;          

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack bị đầy, không thể thêm phần tử!" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rỗng, không thể xóa phần tử!" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack rỗng, không có phần tử nào!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack rỗng!" << endl;
            return;
        }
        cout << "Stack hiện tại: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nChọn thao tác:\n";
        cout << "1. Push (Thêm phần tử vào stack)\n";
        cout << "2. Pop (Xóa phần tử khỏi stack)\n";
        cout << "3. Peek (Xem phần tử trên cùng)\n";
        cout << "4. Hiển thị stack\n";
        cout << "5. Thoát\n";
        cout << "Nhập lựa chọn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhập giá trị cần push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Phần tử trên cùng: " << stack.peek() << endl;
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ, vui lòng nhập lại!\n";
        }
    } while (choice != 5);

    return 0;
}

// MÃ GIẢ:
// BẮT ĐẦU

//     ĐỊNH NGHĨA MAX_SIZE = 100
//     KHAI BÁO MẢNG stack[MAX_SIZE]
//     GÁN top = -1 

//     HÀM isEmpty():
//         TRẢ VỀ (top == -1)

//     HÀM isFull():
//         TRẢ VỀ (top == MAX_SIZE - 1)

//     HÀM push(giá_trị):
//         NẾU isFull() THÌ
//             HIỂN THỊ "Ngăn xếp đầy, không thể thêm phần tử!"
//             TRẢ VỀ
//         KẾT THÚC NẾU
//         top = top + 1
//         stack[top] = giá_trị

//     HÀM pop():
//         NẾU isEmpty() THÌ
//             HIỂN THỊ "Ngăn xếp rỗng, không thể xóa phần tử!"
//             TRẢ VỀ
//         KẾT THÚC NẾU
//         top = top - 1

//     HÀM peek():
//         NẾU isEmpty() THÌ
//             HIỂN THỊ "Ngăn xếp rỗng, không có phần tử nào!"
//             TRẢ VỀ -1
//         KẾT THÚC NẾU
//         TRẢ VỀ stack[top]

//     HÀM display():
//         NẾU isEmpty() THÌ
//             HIỂN THỊ "Ngăn xếp rỗng!"
//             TRẢ VỀ
//         KẾT THÚC NẾU
//         HIỂN THỊ "Ngăn xếp hiện tại: "
//         LẶP i TỪ 0 ĐẾN top
//             HIỂN THỊ stack[i]
//         KẾT THÚC LẶP

//     HÀM main():
//         KHAI BÁO lựa_chọn, giá_trị

//         LẶP
//             HIỂN THỊ "Chọn thao tác:"
//             HIỂN THỊ "1. Push (Thêm phần tử vào ngăn xếp)"
//             HIỂN THỊ "2. Pop (Xóa phần tử khỏi ngăn xếp)"
//             HIỂN THỊ "3. Peek (Xem phần tử trên cùng)"
//             HIỂN THỊ "4. Hiển thị ngăn xếp"
//             HIỂN THỊ "5. Thoát"
//             NHẬP lựa_chọn

//             NẾU lựa_chọn == 1 THÌ
//                 HIỂN THỊ "Nhập giá trị cần push:"
//                 NHẬP giá_trị
//                 GỌI push(giá_trị)

//             NẾU lựa_chọn == 2 THÌ
//                 GỌI pop()

//             NẾU lựa_chọn == 3 THÌ
//                 HIỂN THỊ "Phần tử trên cùng: ", GỌI peek()

//             NẾU lựa_chọn == 4 THÌ
//                 GỌI display()

//             NẾU lựa_chọn == 5 THÌ
//                 HIỂN THỊ "Thoát chương trình."
//                 DỪNG CHƯƠNG TRÌNH

//         KẾT THÚC LẶP

// KẾT THÚC

// ĐÁNH GIÁ ĐỘ PHỨC TẠP:
// O(1) đối với các lệnh pop, push, peek
// O(n) đối với lệnh display khi duyệt cả MẢNG
// Độ phức tạp trung bình là O(n).