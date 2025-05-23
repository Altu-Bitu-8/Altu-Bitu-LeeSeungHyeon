
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> adj[100001];
int dp[100001];
bool visited[100001];
int max_ytree = 0;

int dfs(int node, int parent) {
    visited[node] = true;

    vector<int> lens;

    int t1 = 0, t2 = 0, t3 = 0;
    for (int next : adj[node]) {
        if (next == parent) {
            continue;
        }
        int len = dfs(next, node) + 1;
        lens.push_back(len);
    }

    sort(lens.rbegin(), lens.rend());

    if (lens.size() >= 3) {
        max_ytree = max(max_ytree, lens[0] + lens[1] + lens[2] + 1);
    }

    dp[node] = lens.empty() ? 0 : lens[0];
    return dp[node];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(visited, visited + 100001, false);
    dfs(1, -1);

    cout << max_ytree;

    return 0;
}