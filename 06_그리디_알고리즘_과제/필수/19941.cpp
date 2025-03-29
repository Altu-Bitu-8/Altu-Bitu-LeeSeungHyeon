
#include <iostream>
#include <vector>

using namespace std;

int cntPeople(vector<char>& table, int k) {
    int ans = 0;
    int n = table.size();
    for (int i = 0; i < n; i++) {
        if (table[i] == 'P') { // 사람이면 그리디 알고리즘
            // i를 중심으로 k만큼 탐색 범위 제한
            for (int j = i - k; j <= i + k; j++) {
                if (table[j] == 'H') { // 햄버거 발견!
                    ans++;
                    table[j] = ' '; // 먹어서 없어진 걸 표현
                    break;
                }
            }
        }
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<char> table(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    // 함수 호출
    cout << cntPeople(table, k) << "\n";


    return 0;
}