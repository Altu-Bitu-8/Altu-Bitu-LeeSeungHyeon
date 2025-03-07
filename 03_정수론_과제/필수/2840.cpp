#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 바퀴 초기화 
void setwheel(vector<char>& pan) {
    for (int i = 0; i < pan.size(); i++) {
        pan[i] = '?';
    }
}

// 화살표 위치 업데이트
int updatePos(int currentPos, int cnt, int n) {
    return (currentPos - cnt + n) % n;
}

// 바퀴 업데이트 
bool updateWheel(vector<char>& pan, set<char>& usedLetters, int pos, char value) {
    if (pan[pos] != '?') {
        return pan[pos] == value;
    }
    else {
        if (usedLetters.count(value)) {
            return false;
        }
        pan[pos] = value;
        usedLetters.insert(value);
        return true;
    }
}

// 중복 체크 
bool checkForDuplicates(const vector<char>& pan) {
    for (int i = 0; i < pan.size(); i++) {
        for (int j = i + 1; j < pan.size(); j++) {
            if (pan[i] != '?' && pan[i] == pan[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<char> pan(n, '?');
    set<char> usedLetters;
    int currentPos = 0;

    for (int i = 0; i < k; ++i) {
        int cnt;
        char value;
        cin >> cnt >> value;

        // 화살표 위치 업데이트
        currentPos = updatePos(currentPos, cnt, n);

        // 바퀴 업데이트
        if (!updateWheel(pan, usedLetters, currentPos, value)) {
            cout << "!" << endl;
            return 0;
        }
    }

    // 중복 체크
    if (checkForDuplicates(pan)) {
        cout << "!" << endl;
        return 0;
    }

    // 최종 바퀴 상태 출력
    for (int i = 0; i < n; ++i) {
        cout << pan[currentPos];
        currentPos = (currentPos + 1) % n;
    }
    cout << '\n';

    return 0;
}