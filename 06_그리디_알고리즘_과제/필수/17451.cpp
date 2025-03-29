#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calcMinVelocity(vector<int>& planet) {
    long long ans = planet[0];

    for (int i = 1; i < planet.size(); i++) {
        // 현재 속도가 행성 요구 속도의 정수 배가 되도록 조정
        if (ans % planet[i] != 0) {
            ans = (ans / planet[i] + 1) * planet[i];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    // n의 범위 고려
    long long n;
    cin >> n;

    vector<int> planet(n);

    for (long long i = 0; i < n; i++) {
        cin >> planet[i];
    }

    // 역순으로 비교
    reverse(planet.begin(), planet.end());
    cout << calcMinVelocity(planet) << "\n";

    return 0;
}