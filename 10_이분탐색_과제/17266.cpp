#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// 모든 길을 밝힐 수 있는지 판단하는 함수
bool canLight(int height, const vector<int>& pos, int n) {
    int lastLit = 0;

    for (int i = 0; i < pos.size(); i++) {
        if (pos[i] - height > lastLit) {
            return false;
        }
        lastLit = pos[i] + height;
    }

    return lastLit >= n;
}

// 이분 탐색을 통해 최소 높이 구하기
int solved(int n, int m, vector<int>& pos) {
    int low = 1, high = n, ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canLight(mid, pos, n)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<int> pos(m);
    string input;
    getline(cin, input);
    stringstream ss(input);

    for (int i = 0; i < m; i++) {
        ss >> pos[i];
    }

    cout << solved(n, m, pos) << "\n";

    return 0;
}