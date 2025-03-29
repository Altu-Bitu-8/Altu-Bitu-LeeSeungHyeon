#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> gears; // 각 톱니바퀴의 상태를 저장하는 벡터 (문자열 형태)
vector<bool> visited; // 방문 여부를 저장하는 벡터. 

// 톱니바퀴를 회전시키는 함수
void rotate(int index, int direction) {
    // 시계 방향 회전
    if (direction == 1) { 
        gears[index] = gears[index].back() + gears[index].substr(0, 7); 
    }
    // 반시계 방향 회전
    else { 
        gears[index] = gears[index].substr(1) + gears[index][0]; 
    }
}

// 인접한 톱니바퀴를 확인하고 회전시키는 함수
void check_and_rotate(int index, int direction) {
    visited[index] = true; // 현재 톱니바퀴 방문 처리

    // 왼쪽 톱니바퀴와의 극성 확인
    if (index > 0 && !visited[index - 1] && gears[index][6] != gears[index - 1][2]) {
        // 다르면 반대 방향 회전
        check_and_rotate(index - 1, -direction); 
    }

    // 오른쪽 톱니바퀴와의 극성 확인
    if (index < gears.size() - 1 && !visited[index + 1] && gears[index][2] != gears[index + 1][6]) {
        // 다르면 반대 방향 회전
        check_and_rotate(index + 1, -direction); 
    }
    // 현재 톱니바퀴 회전
    rotate(index, direction); 
}

int main() {
    int t, k;
    cin >> t; // 톱니바퀴 개수 입력
    gears.resize(t); // 톱니바퀴 벡터 크기

    // 각 톱니바퀴 상태 입력
    for (int i = 0; i < t; ++i)
        cin >> gears[i];
    // 회전 명령 횟수 입력
    cin >> k; 
    while (k--) {
        int num, direction;
        // 회전할 톱니바퀴의 번호, 방향 입력
        cin >> num >> direction; 

        visited.assign(t, false); // 방문 여부 초기화
        check_and_rotate(num - 1, direction); // 선택된 톱니바퀴부터 회전 시작
    }

    // 첫 번째 톱니바퀴의 극이 S(1)인지 확인
    int result = 0;
    for (const auto& gear : gears) {
        // 가장 앞에 있는 비트를 확인
        if (gear[0] == '1') result++; 
    }

    cout << result << endl; // 결과 출력
    return 0;
}
