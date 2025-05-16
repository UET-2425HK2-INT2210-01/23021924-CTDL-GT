// ý tưởng

// duyệt ma trận kề O(n^3)
// for (k<n)
//     for(i<n)
//         for (j<n)
//             if (d[i,j] > d[i,k] + d[k,j])
//                 update d(i,j);


#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;    // nhập số thành phố n, số đường m, điểm bắt đầu s, điểm kết thúc e
    s--; e--;  // chuyển về 0-based

    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> next(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;
    }
    
    // nhập m cạnh có định dạng u v d
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        dist[u][v] = d;
        next[u][v] = v;
    }

    // Floyd-Warshall với truy vết
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }

    // In tổng độ bẩn từ s -> e
    if (dist[s][e] == INF) {
        cout << "INF\n";
    } else {
        cout << dist[s][e] << "\n";     // in tong do ban nho nhat

        // Truy vết đường đi
        vector<int> path;
        int cur = s;
        while (cur != e) {
            path.push_back(cur);
            cur = next[cur][e];
            if (cur == -1) break;
        }
        path.push_back(e);
        
        // in duong di
        for (int i = 0; i < path.size(); ++i) {
            cout << (path[i] + 1);
            if (i != path.size() - 1) cout << " ";
        }
        cout << "\n";
    }

    // In ma trận dist
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
