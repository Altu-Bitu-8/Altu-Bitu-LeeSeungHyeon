#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, char color, vector<vector<bool>>& visited, const vector<vector<char>>& grid) {
    int n = grid.size();
    int dx[] = { -1,1,0,0 };
    int dy[] = { 0,0,-1,1 };

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && grid[nx][ny] == color) {
                dfs(nx, ny, color, visited, grid);
            }
        }
    }

}

// 정상 시야
int cntNormal(const vector<vector<char>>& grid) {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int regions = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j], visited, grid);
                regions++;
            }
        }
    }

    return regions;
}
// 적록색맹
int cntRG(const vector<vector<char>>& grid) {
    int n = grid.size();
    vector<vector<char>> updategrid = grid;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int regions = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (updategrid[i][j] == 'G') {
                updategrid[i][j] = 'R';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, updategrid[i][j], visited, updategrid);
                regions++;
            }
        }
    }
    return regions;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<bool>> visited_normal(n, vector<bool>(n, false));
    vector<vector<bool>> visited_rg(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int normal_regions = cntNormal(grid);
    int rg_regions = cntRG(grid);

    cout << normal_regions << " " << rg_regions << "\n";

    return 0;
}