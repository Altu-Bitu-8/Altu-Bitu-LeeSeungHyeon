#include <iostream>
#include <deque>

using namespace std;

struct info { // 컨베이어 벨트의 각 칸을 나타내는 구조체
    int power; // 내구도 (칸이 견딜 수 있는 횟수)
    bool is_on = false; // 로봇이 해당 칸에 있는지 여부
};

// 벨트를 한 칸 회전시키는 함수
void rotateBelt(deque<info>& belt, int n) {
    belt.push_front(belt.back()); // 벨트의 마지막 칸을 가장 앞쪽으로 이동
    belt.pop_back();              // 벨트의 기존 마지막 칸 제거
    belt[n - 1].is_on = false;    // 이동 후, 내리는 위치(n-1)에서 로봇을 제거
}

// 로봇을 이동할 수 있으면 한 칸 앞으로 이동시키는 함수
void moveRobot(deque<info>& belt, int n) {
    // 로봇이 이동해야 하는 순서를 고려하여, 뒤쪽 칸부터 앞으로 이동
    for (int i = n - 2; i >= 0; i--) { // 가장 끝에서부터 이동 검사
        // 현재 칸에 로봇이 있으며, 다음 칸이 비어 있고, 내구도가 남아 있는 경우 이동 가능
        if (belt[i].is_on && !belt[i + 1].is_on && (belt[i + 1].power >= 1)) {
            belt[i].is_on = false;    // 현재 위치의 로봇 제거
            belt[i + 1].is_on = true; // 다음 칸으로 로봇 이동
            belt[i + 1].power--;      // 이동한 칸의 내구도 감소
        }
    }
    belt[n - 1].is_on = false; // 내리는 위치에 도착한 로봇 제거
}

// 올리는 위치(첫 번째 칸)에 로봇을 올릴 수 있으면 올리는 함수
void putRobot(deque<info>& belt) {
    // 올리는 칸의 내구도가 남아 있는 경우, 로봇을 올릴 수 있음
    if (belt[0].power >= 1) {
        belt[0].is_on = true; // 로봇을 올림
        belt[0].power--;      // 해당 칸의 내구도 감소
    }
}

// 벨트 내구도 상태를 확인하는 함수
bool checkFinish(deque<info>& belt, int n, int k) {
    int cnt = 0; // 내구도가 0인 칸의 개수를 저장할 변수
    for (int i = 0; i < 2 * n; i++) { // 전체 벨트 검사
        if (belt[i].power == 0) {
            cnt++; // 내구도가 0인 칸 개수 증가
        }
    }
    return cnt >= k; // 내구도 0인 칸이 k개 이상이면 종료 조건 충족
}

// 벨트의 모든 작업을 수행하고 종료 조건을 만족할 때까지 반복하는 함수
int solution(deque<info>& belt, int n, int k) {
    int step = 1; // 현재 단계(반복 횟수)
    while (true) {
        rotateBelt(belt, n); // 1. 벨트 회전
        moveRobot(belt, n);  // 2. 로봇 이동
        putRobot(belt);      // 3. 로봇 올리기

        // 4. 내구도가 0인 칸이 k개 이상이면 종료
        if (checkFinish(belt, n, k)) {
            return step; // 현재 진행된 단계(step)를 반환
        }
        step++; // 단계 증가
    }
}

int main()
{
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, k; // 컨베이어 벨트 길이(n), 내구도가 0이 된 칸의 최대 개수(k)
    cin >> n >> k;
    deque<info> belt(2 * n); // 컨베이어 벨트 크기 초기화 (2n 크기의 벨트)

    // 각 칸의 내구도를 입력받음
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power;
    }

    // 연산 수행 후 결과 출력
    cout << solution(belt, n, k);
}