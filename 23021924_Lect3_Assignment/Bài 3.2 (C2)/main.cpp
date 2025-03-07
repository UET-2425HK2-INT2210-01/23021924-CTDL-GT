#include <iostream>
using namespace std;

long long power_iterative(int N) {
    long long result = 1; // Khởi tạo kết quả là 1
    for (int i = 1; i <= N; i++) {
        result *= 2; // Nhân dồn với 2
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    cout << power_iterative(N);
    return 0;
}


// MÃ GIẢ:
// HÀM power_iterative(N)
//     KHAI BÁO result = 1
//     LẶP i từ 1 đến N
//         result = result * 2
//     TRẢ VỀ result

// CHƯƠNG TRÌNH CHÍNH
//     NHẬP N
//     HIỂN THỊ power_iterative(N)


// Độ phức tạp thuật toán O(log(n)).