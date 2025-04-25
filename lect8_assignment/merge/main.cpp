#include <iostream>
using namespace std;

// Hàm trộn hai mảng con đã sắp xếp
void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double L[1000], R[1000]; // Mảng tạm để chứa hai nửa

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Trộn hai mảng lại
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sao chép phần còn lại nếu có
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Hàm Merge Sort đệ quy
void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);       // Sắp xếp nửa trái
        mergeSort(arr, mid + 1, right);  // Sắp xếp nửa phải
        merge(arr, left, mid, right);    // Trộn lại
    }
}

int main() {
    int n;
    cin >> n;

    double arr[1000]; // Giả sử n <= 1000

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }

    return 0;
}
