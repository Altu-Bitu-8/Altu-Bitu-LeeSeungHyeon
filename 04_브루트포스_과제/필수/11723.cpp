#include <iostream>
#include <string>
using namespace std;


int s = 0;

// 연산 수행 함수(비트 마스킹)

void calc(string operation, int x = 0) {
    if (operation == "add") {
        // 집합에 x를 추가한다.
        int bitmask = (1 << (x - 1));
        // x에 해당하는 비트를 1로 설정
        s = s | bitmask;
    }
    else if (operation == "remove") {
        // 집합에서 x를 제거한다.
        int bitmask = ~(1 << (x - 1));
        s = s & bitmask;
    }
    else if (operation == "check") {
        // 집합에 x가 포함되어 있는지 확인
        int bitmask = (1 << (x - 1));
        if ((s & bitmask) != 0) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    else if (operation == "toggle") {
        // 집합에서 x를 토글한다.
        int bitmask = (1 << (x - 1));
        // 비트 반전
        s = s ^ bitmask; 
    }
    else if (operation == "all") {
        // {1, 2, ..., 20}으로 설정한다.
        // 모든 비트를 1
        s = (1 << 20) - 1;
    }
    else if (operation == "empty") {
        // 공집합
        // 모든 비트를 0
        s = 0;
    }

}

int main() {
    // 빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt;
    cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        string operation;
        int x = 0;

        cin >> operation;
        if (operation == "add" || operation == "remove" || operation == "check" || operation == "toggle") {
            cin >> x;
        }

        calc(operation, x);
    }

    return 0;
}