#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 단어와 알파벳 빈도수를 저장하는 구조체
struct WordInfo {
    int alpha[26] = { 0 };

    // 생성자: 단어를 받아 알파벳 빈도를 계산
    // ex 기준 : [2,2,0,0, ..]
    //    비교 : [1,2,0,0, ..]
    WordInfo(const string& word) {
        for (char c : word) {
            int index = c - 'A';
            alpha[index]++;
        }
    }

    // 비슷한 단어인지 확인
    bool isSimilar(const WordInfo& other, int lendiff) {
        if (abs(lendiff) > 1) {
            return false;
        }

        int diff = 0;
        for (int i = 0; i < 26; i++) {
            // 각 알파벳 차이를 계산. 누적. 
            diff += abs(alpha[i] - other.alpha[i]);
        }
        // 비슷한 단어. 
        return diff <= 2;
    }
};

int main() {
    int n, cnt = 0;
    string base, word;

    cin >> n >> base;
    WordInfo baseInfo(base);

    for (int i = 0; i < n - 1; i++) {
        cin >> word;
        WordInfo targetInfo(word);

        if (baseInfo.isSimilar(targetInfo, base.size() - word.size())) {
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}