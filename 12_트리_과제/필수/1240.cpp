#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[1001];
bool visited[1001];

int bfs(int start, int end) {
    queue<pair<int, int>> q;
    q.push({ start,0 });

    fill(visited, visited + 1001, false);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        // 목표 노드 도달
        if (cur == end) {
            return dist;
        }

        for (auto next : adj[cur]) {
            if (!visited[next.first]) {
                visited[next.first] = true;
                q.push({ next.first,dist + next.second });
            }
        }
    }

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    //tree

    for (int i = 0; i < n - 1; i++) {
        int x, y, dist;
        cin >> x >> y >> dist;
        adj[x].push_back({ y,dist });
        adj[y].push_back({ x,dist });
    }

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;


        cout << bfs(start, end) << "\n";
    }
    return 0;
}