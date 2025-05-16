// Ý tưởng
// cin>>n>>m
// vector<vector<nf>> adj(n+1)
// for(i<n)
//     int x,y
//     cin>>x>>y
//     adj[x].push(y)
//     adj[y].push(x)

// dfs(n+v) 
//     visited[u]=true
//     for(v_next:adj[v])
//         if(visited[v_next]==false)
//             dfs(v_n)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // danh sách kề
vector<bool> visited;    // mảng đánh dấu đã thăm

// duyệt theo chiều sâu
void dfs(int v) {
    visited[v] = true;
    for (int v_next : adj[v]) {
        if (!visited[v_next]) {
            dfs(v_next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n + 1);  // danh sách kề từ 1 đến n
    visited = vector<bool>(n + 1, false);  // đánh dấu chưa thăm

    // Nhập các cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int components = 0;
    //  thăm lần lượt từng node cho đến hết
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    cout << components << endl;
    return 0;
}
