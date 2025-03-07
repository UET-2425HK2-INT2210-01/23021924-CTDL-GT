#include <iostream>
using namespace std;

double bitleft(int n){
    double result;
    if (n>=0){
        result = 1 <<n;
    } else {
        result = 1 << -(n);
        result = 1/result;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    cout << bitleft(n);
    return 0;
}

// MÃ GIẢ:
// HÀM bitleft(n)
//     Khai báo biến result kiểu số thực
//     Nếu n >= 0
//         result = 1 dịch trái n bit
//     Ngược lại
//         result = 1 dịch trái |n| bit
//         result = 1 / result
//     Trả về result

// CHƯƠNG TRÌNH CHÍNH
//     Khai báo biến n kiểu số nguyên
//     Nhập n từ người dùng
//     Hiển thị kết quả của hàm bitleft(n)
//     Kết thúc chương trình

// Độ phức tạp thuật toán O(1).