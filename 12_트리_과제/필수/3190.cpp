#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<pair<int, int>> snake_body;
int dx[4] = { 0, 1, 0, -1 }; // 오른쪽, 아래, 왼쪽, 위
int dy[4] = { 1, 0, -1, 0 };

// 뱀 이동 함수
bool moveSnake(int dir, vector<vector<int>>& board) {
    int nx = snake_body.front().first + dx[dir];
    int ny = snake_body.front().second + dy[dir];

    // 게임 종료
    for (const auto& seg : snake_body) {
        if (seg.first == nx && seg.second == ny) {
            return false; // 자기 몸과 충돌하면 게임 종료
        }
    }

    if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board.size()) {
        return false; // 벽에 충돌하면 게임 종료
    }


    // 머리 이동
    snake_body.push_front({ nx, ny });

    // 사과 확인
    if (board[nx][ny] == 1) {
        board[nx][ny] = 0; // 사과 먹기
    }
    else {
        snake_body.pop_back(); // 사과 없으면 꼬리 제거
    }

    return true;
}

// 시간 반환 함수
int timeOut(vector<vector<int>>& board, vector<pair<int, char>>& snake_moves) {
    int ans = 0;
    int dir = 0;
    int index = 0;

    snake_body.push_back({ 0, 0 });

    while (moveSnake(dir, board)) {
        ans++;

        // 방향 반환
        if (index < snake_moves.size() && snake_moves[index].first == ans) {
            if (snake_moves[index].second == 'L') {
                dir = (dir + 3) % 4;
            }
            else {
                dir = (dir + 1) % 4;
            }
            index++;
        }
    }

    return ans + 1; // 게임이 끝나는 순간 포함
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    // 사과
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }

    // 뱀
    int l;
    cin >> l;
    vector<pair<int, char>> snake_moves(l);
    for (int i = 0; i < l; i++) {
        cin >> snake_moves[i].first >> snake_moves[i].second;
    }

    // 출력
    cout << timeOut(board, snake_moves) << "\n";

    return 0;
}