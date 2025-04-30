#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj; // 인접 리스트
vector<bool> visited;    // 방문 여부

int bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    int cnt = 0;

    while (!q.empty()) {
        int now_Node = q.front();
        q.pop();

        for (int i : adj[now_Node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);        // 인접 리스트 크기 설정
    visited.resize(n + 1);    // 방문 배열 크기 설정

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    cout << bfs(1) << endl;

    return 0;
}