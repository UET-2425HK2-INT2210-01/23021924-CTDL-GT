#include <iostream>
using namespace std;

// Hàm hoán đổi 2 phần tử
void swap(double &a, double &b) {
    double temp = a;                            //Biến tạm, gán giá trị của a
    a = b;                                      // gán giá trị b cho a
    b = temp;                                   // gán giá trị biến tạm cho b    
}

// Hàm phân hoạch cho Quick Sort
int partition(double arr[], int l, int r) {
    double pivot = arr[r];                   //chọn pivot là phần tử cuối arr
    int i = l - 1;                            //i bắt đầu từ trước phần tử đầu tiên của arr

    for (int j = l; j < r; j++) {          //vòng lặp cho biến chạy từ đầu đến phần tử trước pivot
        if (arr[j] < pivot) {                   // nếu phần tử đang xét nhỏ hơn pivot
            i++;                                //tăng i
            swap(arr[i], arr[j]);               //đổi vị trí 2 phân tử
        }
    }
    swap(arr[i + 1], arr[r]);                //đổi vị trí, đưa pivot vào giữa 2 phần (phần nhỏ và phần lớn hơn pivot)
    return i + 1;
}

// Hàm quick sort đệ quy
void quickSort(double arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);

        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main() {
    int n;
    cin >> n;

    double arr[1000]; // Giả định n <= 1000
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }

    return 0;
}
