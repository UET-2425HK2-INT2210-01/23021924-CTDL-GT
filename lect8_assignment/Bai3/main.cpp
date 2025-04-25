#include <iostream>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;

    int weight[1000], value[1000]; // giả sử n <= 1000
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    // dp[i] là giá trị lớn nhất có thể đạt được với tổng trọng lượng i
    int dp[1001] = {0}; // giả sử X <= 1000

    // Duyệt từng vật
    for (int i = 0; i < n; i++) {
        // Duyệt ngược để tránh dùng lại vật i nhiều lần
        for (int j = X; j >= weight[i]; j--) {
            // Cập nhật giá trị lớn nhất có thể đạt tại trọng lượng j
            if (dp[j - weight[i]] + value[i] > dp[j]) {
                dp[j] = dp[j - weight[i]] + value[i];
            }
        }
    }

    // Tìm giá trị lớn nhất trong dp[0..X]
    int maxValue = 0;
    for (int i = 0; i <= X; i++) {
        if (dp[i] > maxValue) {
            maxValue = dp[i];
        }
    }

    cout << maxValue;
    return 0;
}
