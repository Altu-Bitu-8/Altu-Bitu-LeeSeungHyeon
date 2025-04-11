#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj; // 인접 리스트
vector<bool> visited;    // 방문 여부

int bfs(int start, int target) {
    queue<pair<int, int>> q; // (현재 노드, 깊이)
    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        int now_Node = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (now_Node == target) {
            // 목표 노드에 도달하면 깊이 반환
            return depth;
        }

        for (int next_Node : adj[now_Node]) {
            if (!visited[next_Node]) {
                visited[next_Node] = true;
                q.push({ next_Node, depth + 1 });
            }
        }
    }
    // 목표 노드에 도달하지 못한 경우
    return -1;
}

int main() {
    int n, m;
    cin >> n;

    int n1, n2;
    cin >> n1 >> n2;

    cin >> m;

    adj.resize(n + 1);        // 인접 리스트 크기 설정
    visited.resize(n + 1, false); // 방문 배열 초기화

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    cout << bfs(n1, n2) << "";

    return 0;
}