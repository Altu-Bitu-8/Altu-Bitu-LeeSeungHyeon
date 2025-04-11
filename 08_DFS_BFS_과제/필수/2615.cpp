#include <iostream>
#include <vector>

using namespace std;

void dfs(int x, int y, int dir_x, int dir_y, int& cnt, const vector<vector<int>>& chess, int color) {
    int n = chess.size();
    int nx = x + dir_x;
    int ny = y + dir_y;

    if (nx >= 0 && nx < n && ny >= 0 && ny < n && chess[nx][ny] == color) {
        cnt++;
        dfs(nx, ny, dir_x, dir_y, cnt, chess, color);
    }
}
// 승리 조건 탐색 함수
bool isVictory(int x, int y, const vector<vector<int>>& chess, int color) {
    int dx[] = { 1,0,1,-1 };
    int dy[] = { 0,1,1,1 };

    for (int i = 0; i < 4; i++) {
        int cnt = 1;
        dfs(x, y, dx[i], dy[i], cnt, chess, color);

        // 6개 제한
        int reverse = 0;
        // 시작점의 반대 방향 탐색
        dfs(x, y, -dx[i], -dy[i], reverse, chess, color);

        if (cnt + reverse == 5) {
            int nx = x - dx[i];
            int ny = y - dy[i];
            if (nx >= 0 && nx < chess.size() && ny >= 0 && ny < chess.size() && chess[nx][ny] == color) {
                continue; // 육목이면 무시
            }
            return true;
        }
    }
    return false;

}


int main()
{
    vector<vector<int>> chess(19, vector<int>(19));


    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> chess[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            // 바둑알이 있는 칸만 검사
            if (chess[i][j] != 0 && isVictory(i, j, chess, chess[i][j])) {
                cout << chess[i][j] << "\n";
                cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
    }


    cout << 0 << "\n";
    return 0;
}