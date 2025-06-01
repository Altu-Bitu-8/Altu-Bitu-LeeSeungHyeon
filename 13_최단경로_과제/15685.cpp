#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
bool grid[101][101] = { false };

void drawDragonCurve(int x, int y, int d, int g) {
    vector<int> dir;
    dir.push_back(d);

    // 세대별 방향 확장
    for (int i = 0; i < g; i++) {
        int size = dir.size();
        for (int j = size - 1; j >= 0; j--) {
            dir.push_back((dir[j] + 1) % 4);
        }
    }
    // 드래곤 커브 그리기
    grid[x][y] = true;
    for (int i : dir) {
        x += dx[i];
        y += dy[i];
        if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
            grid[x][y] = true;
        }
    }
}

int cntSquare() {
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dragon(n);
    // x, y 시작점, d는 시작 방향, g는 세대
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        drawDragonCurve(x, y, d, g);
    }

    cout << cntSquare() << "\n";
    return 0;
}