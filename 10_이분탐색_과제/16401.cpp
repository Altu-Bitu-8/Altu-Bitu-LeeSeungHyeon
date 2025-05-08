
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDiv(const vector<int>& snack, int m, int len) {
    int cnt = 0;
    for (int s : snack) {
        cnt += s / len;
    }
    // 조카들에게 나눠줄 수 있는지
    return cnt >= m;
}

int binarySearch(const vector<int>& snack, int m) {
    int left = 1, right = *max_element(snack.begin(), snack.end());
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canDiv(snack, m, mid)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;

}

int main()
{
    int m;
    int n;
    cin >> m >> n;

    vector<int> snack(n);

    for (int i = 0; i < size(snack); i++) {
        cin >> snack[i];
    }

    cout << binarySearch(snack, m) << "\n";

    return 0;
}