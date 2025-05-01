#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(int start, int current, int cnt, int cost, vector<vector<int>>& w, vector<bool>& visited, int& min_result) {
    if (cnt == w.size()) {
        // 모든 도시를 방문한 후 출발점으로 돌아오는 조건
        if (w[current][start] > 0) {
            min_result = min(min_result, cost + w[current][start]);
        }
        return;
    }

    for (int i = 0; i < w.size(); i++) {
        if (!visited[i] && w[current][i] > 0) {
            visited[i] = true;
            backtrack(start, i, cnt + 1, cost + w[current][i], w, visited, min_result);
            visited[i] = false; // 백트래킹 후 복구
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> w(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    // 초기값 설정
    int min_result = 1e9;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        visited[i] = true;
        backtrack(i, i, 1, 0, w, visited, min_result);
    }

    cout << min_result << "\n";

    return 0;
}