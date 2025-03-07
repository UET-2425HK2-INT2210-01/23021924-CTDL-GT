#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, value;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

// MÃ GIẢ:
// HÀM main():
//     KHAI BÁO queue q
//     KHAI BÁO n, value
    
//     HIỂN THỊ "Nhập số lượng phần tử cần thêm vào queue: "
//     NHẬP n

//     LẶP i từ 0 đến n-1:
//         HIỂN THỊ "Nhập giá trị phần tử thứ", i+1, ": "
//         NHẬP value
//         q.push(value) // Đẩy giá trị vào hàng đợi
//         HIỂN THỊ "Đã push", value, "vào queue."

//     HIỂN THỊ "Các phần tử trong queue (theo thứ tự FIFO): "
    
//     LẶP KHI q không rỗng:
//         HIỂN THỊ q.front() // Lấy phần tử đầu tiên
//         q.pop() // Xóa phần tử đầu tiên

//     HIỂN THỊ xuống dòng
// KẾT THÚC HÀM main()

// Độ phức tạp thuật toán O(n).