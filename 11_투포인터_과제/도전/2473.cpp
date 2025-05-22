
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

vector<int> twoPointer(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());
    vector<int> ans(3);
    long long closest_sum = LLONG_MAX;

    // 첫 번째 용액은 고정, 나머지는 투 포인터
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;

        while (left < right) {
            long long sum = (long long)arr[i] + arr[left] + arr[right];

            // 0에 더 가까운 합을 찾아야 함.
            if (abs(sum) < abs(closest_sum)) {
                closest_sum = sum;
                ans = { arr[i],arr[left],arr[right] };
            }

            if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = twoPointer(arr, n);
    cout << result[0] << " " << result[1] << " " << result[2] << "\n";

    return 0;
}