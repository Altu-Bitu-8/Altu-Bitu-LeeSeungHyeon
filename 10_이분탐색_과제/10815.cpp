#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(const vector<int>& card, int target) {
    int low = 0, high = card.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (card[mid] == target)
        {
            return true;
        }
        else if {
            (card[mid] < target) low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> card(n);
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    cin >> m;
    vector<int> correct(m);
    for (int i = 0; i < m; i++) {
        cin >> correct[i];
    }

    // 숫자 카드 정렬 (이진 탐색을 위해)
    sort(card.begin(), card.end());

    // 각 숫자가 존재하는지 확인
    for (int i = 0; i < m; i++) {
        cout << binarySearch(card, correct[i]) << " ";
    }

    return 0;
}