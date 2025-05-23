#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // tạo vector 2 chiều với n+1 đỉnh; vector 1 chiều khởi tạo tất cả bằng 0
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);

    // Đọc m dòng yêu cầu: u v nghĩa là u phải trước v
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;

    // Thêm các đỉnh có in-degree = 0 vào hàng đợi
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    // Thuật toán sắp xếp topo (Kahn)
    while (!q.empty()) {    //xét hết các vector
        int node = q.front();
        q.pop();
        result.push_back(node);     // lấy đỉnh hàng đợi cho vào vector kết quả

        for (int neighbor : graph[node]) {
            in_degree[neighbor]--;  //duyệt qua các đinht liền kề
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Kiểm tra đồ thị có chu trình không
    if (result.size() != n) {
        cout << "Cycle detected. No valid job ordering.\n";
    } else {
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i != result.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
