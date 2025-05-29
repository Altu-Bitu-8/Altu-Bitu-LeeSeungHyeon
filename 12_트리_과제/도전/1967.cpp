
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[10001];
bool visited[10001];
int max_dist = 0;
int farthest_node = 0;

void dfs(int node, int dist) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;

    // 가장 먼 노드 구하기
    if (dist > max_dist) {
        max_dist = dist;
        farthest_node = node;
    }

    for (auto next : adj[node]) {
        dfs(next.first, dist + next.second);
    }
}


int main()
{
    int n;
    cin >> n;

    // 트리 입력
    for (int i = 0; i < n - 1; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        adj[parent].push_back({ child,weight });
        adj[child].push_back({ parent,weight });
    }

    // 1. 가장 먼 노드 찾기
    fill(visited, visited + 10001, false);
    dfs(1, 0);

    // 2. 트리 지름 계산
    fill(visited, visited + 10001, false);
    max_dist = 0;
    dfs(farthest_node, 0);

    // 3. 지름 출력
    cout << max_dist;
    return 0;
}