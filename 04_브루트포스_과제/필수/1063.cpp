#include <iostream>
#include <string>

using namespace std;

// 체스판 범위 확인 함수
bool isInBoard(int x, int y) {
    if (x >= 0 && x < 8) {
        if (y >= 0 && y < 8) {
            return true;
        }
    }
    return false;
}

// 이동 방향 초기화 함수
void setMov(const string& movement, int& move_x, int& move_y) {
    move_x = 0;
    move_y = 0;

    if (movement == "R") { move_x = 1; }
    else if (movement == "L") {
        move_x = -1;
    }
    else if (movement == "B") {
        move_y = -1;
    }
    else if (movement == "T") {
        move_y = 1;
    }
    else if (movement == "RT") {
        move_x = 1;
        move_y = 1;
    }
    else if (movement == "LT") {
        move_x = -1;
        move_y = 1;
    }
    else if (movement == "RB") {
        move_x = 1;
        move_y = -1;
    }
    else if (movement == "LB") {
        move_x = -1;
        move_y = -1;
    }
}

int main() {
    string king, stone;
    int cnt;
    cin >> king >> stone >> cnt;

    // 킹과 돌의 초기 위치
    int king_x = king[0] - 'A';
    int king_y = king[1] - '1';
    int stone_x = stone[0] - 'A';
    int stone_y = stone[1] - '1';

    for (int i = 0; i < cnt; i++) {
        string movement;
        cin >> movement;

        // 이동 방향 초기화
        int move_x, move_y;
        setMov(movement, move_x, move_y);

        // 킹 이동
        int next_king_x = king_x + move_x;
        int next_king_y = king_y + move_y;

        // 킹이 체스판 안에 있는 경우
        if (isInBoard(next_king_x, next_king_y)) {
            // 돌과 겹치는 경우
            if (next_king_x == stone_x && next_king_y == stone_y) {
                int next_stone_x = stone_x + move_x;
                int next_stone_y = stone_y + move_y;

                // 돌도 체스판 안에 있어야함.
                if (isInBoard(next_stone_x, next_stone_y)) {
                    stone_x = next_stone_x;
                    stone_y = next_stone_y;
                    king_x = next_king_x;
                    king_y = next_king_y;
                }
            }
            else {
                // 돌과 충돌하지 않으면 킹만 이동
                king_x = next_king_x;
                king_y = next_king_y;
            }
        }
    }

    // 결과 출력
    cout << char(king_x + 'A') << char(king_y + '1') << endl;
    cout << char(stone_x + 'A') << char(stone_y + '1') << endl;

    return 0;
}