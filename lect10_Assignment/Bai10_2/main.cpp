// ý tưởng
// bfs(int v)
//     vector<int>visited([n+1], false)
//     queue<int>q
//     q.enque(v)
//     visited[v]=true
//     while(!q.empty())
//         int v_i=q.dequeue(), q.front(*)
//         q.dequeue()
//         for()
//             if visited(v_n)=true
//                 q.enqueue
    
    
    
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    vector<vector<int>> adj(n + 1); // khởi tạo danh sách kề(đồ thị đánh số từ 1 đến n+1)
    
    // m cạnh đồ thị
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Đồ thị có hướng u->v
    }
    
    // mảng đánh dấu đỉnh đã thăm
    vector<bool> visited(n + 1, false);
    
    // mảng lưu số cạnh đến đỉnh khác
    vector<int> dist(n + 1, -1);
    
    queue<int> q; 
    q.push(X);          // thêm X cuối hàng đợi
    visited[X] = true;  // đánh dấu đã thăm
    dist[X] = 0;        // X đến X bằng 0
    
    // vòng lặp bfs
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // duyệt tất cả đỉnh kề u
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;      //đánh dấu đã thăm u 
                dist[v] = dist[u] + 1;  // cập nhật khoảng cách
                q.push(v);              // thêm v vào hàng đợi
            }
        }
    }
    
    // In khoảng cách ngắn nhất
    cout << dist[Y] << endl;

    return 0;
}
