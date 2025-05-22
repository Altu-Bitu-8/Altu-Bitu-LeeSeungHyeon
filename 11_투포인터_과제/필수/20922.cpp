
#include <iostream>
#include <vector>

using namespace std;

int twoPointer(vector<int>& arr, int n, int k)
{
    vector<int> cnt(100001, 0);
    int left = 0, right = 0, ans = 0;

    while (right < n) {
        cnt[arr[right]]++;

        // 같은 숫자 k번 초과 : left 만큼 이동
        while (cnt[arr[right]] > k) {
            cnt[arr[left]]--;
            left++;
        }
        ans = max(ans, (right - left) + 1);
        right++;
    }


    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << twoPointer(arr, n, k) << "\n";
    return 0;
}