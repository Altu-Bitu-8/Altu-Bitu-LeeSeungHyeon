
#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

void floydWarshall(vector<vector<int>>& adj, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (adj[j][i] && adj[i][k]) {
                    adj[j][k] = 1;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
    }

    floydWarshall(adj, n);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int known = 0;
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] || adj[j][i]) {
                known++;
            }
        }
        if (known == n - 1) {
            cnt++;
        }
    }
    cout << cnt << "\n";


    return 0;
}