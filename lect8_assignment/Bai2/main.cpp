#include <iostream>
using namespace std;

bool checkSubset(int arr[], int n, int x, int index = 0, int currentSum = 0) {
    if (currentSum == x) return true;                       //Nếu tổng bằng x, trả về true
    if (index == n || currentSum > x) return false;         //Nếu đã xét hết n phần tử, hoặc tổng lớn hơn x, trả về false

    // Chọn phần tử tại index
    if (checkSubset(arr, n, x, index + 1, currentSum + arr[index])) return true;    //Gọi đệ quy tính tổng

    // Không chọn phần tử tại index
    if (checkSubset(arr, n, x, index + 1, currentSum)) return true;                 //Gọi đệ quy tính tổng

    return false;               //Nếu 2 trường hợp đều không thỏa mãn, trả về false
}

int main() {
    int n, x;
    cin >> n >> x;

    int arr[1000]; // Giả định n <= 1000
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (checkSubset(arr, n, x))     // Gọi hàm tính tổng, so sánh với x
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
