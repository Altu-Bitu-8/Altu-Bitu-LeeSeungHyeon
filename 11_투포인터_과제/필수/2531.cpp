
#include <iostream>
#include <vector>


using namespace std;

int twoPointer(vector<int>& line, int n, int d, int k, int c) {
    vector<int> cnt(d + 1, 0);
    int ans = 0, cur = 0;

    for (int i = 0; i < k; i++) {
        // 처음 보는 초밥인 경우만
        if (cnt[line[i]] == 0) {
            cur++;
        }
        // 각 초밥이 몇 번 등장했는지
        cnt[line[i]]++;
    }
    // 쿠폰 고려
    ans = cur + (cnt[c] == 0 ? 1 : 0);

    //슬라이딩 윈도우
    for (int i = 0; i < n; i++) {
        int del = i;
        int add = (i + k) % n;
        // 맨앞 초밥 제거
        cnt[line[del]]--;
        if (cnt[line[del]] == 0) {
            cur--;
        }
        // 초밥 추가
        if (cnt[line[add]] == 0) {
            cur++;
        }
        cnt[line[add]]++;
        // 쿠폰 고려하여 최대 종류 갱신
        ans = max(ans, cur + (cnt[c] == 0 ? 1 : 0));
    }

    return ans;
}


int main()
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> line(n);

    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }

    cout << twoPointer(line, n, d, k, c) << "\n";
    return 0;
}