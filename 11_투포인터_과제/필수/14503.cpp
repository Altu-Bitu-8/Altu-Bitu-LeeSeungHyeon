#include <iostream>
#include <vector>

using namespace std;

// 방향: 북(0) → 동(1) → 남(2) → 서(3)
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int cleanRoom(vector<vector<int>>& room, int n, int m, int r, int c, int d) {
    int ans = 0;

    while (true) {
        // 1. 현재 위치 청소
        if (room[r][c] == 0) {
            room[r][c] = 2;  // 2를 사용해서 청소 완료 표시
            ans++;
        }

        bool found = false;
        for (int i = 0; i < 4; i++) {
            // 2. 반시계 방향 회전
            d = (d + 3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];

            // 3. 청소되지 않은 칸이 있으면 이동
            if (room[nx][ny] == 0) {
                r = nx;
                c = ny;
                found = true;
                break;
            }
        }

        // 4. 주변에 청소할 곳이 없으면 후진
        if (!found) {
            int backDir = (d + 2) % 4;
            int bx = r + dx[backDir];
            int by = c + dy[backDir];

            // 벽이면 종료
            if (room[bx][by] == 1) break;

            // 후진 가능하면 이동
            r = bx;
            c = by;
        }
    }

    return ans;
}

int main() {
    int n, m, r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;

    vector<vector<int>> room(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> room[i][j];

    cout << cleanRoom(room, n, m, r, c, d) << "\n";

    return 0;
}