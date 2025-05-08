
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;


void backtrack(int idx, int current, vector<int>& arr, vector<int>& op, int& max_result, int& min_result)
{
    if (idx == arr.size()) {
        max_result = max(max_result, current);
        min_result = min(min_result, current);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            switch (i) {
            case 0:
                backtrack(idx + 1, current + arr[idx], arr, op, max_result, min_result);
                break;
            case 1:
                backtrack(idx + 1, current - arr[idx], arr, op, max_result, min_result);
                break;
            case 2:
                backtrack(idx + 1, current * arr[idx], arr, op, max_result, min_result);
                break;
            case 3:
                backtrack(idx + 1, current / arr[idx], arr, op, max_result, min_result);
                break;
            }
            op[i]++;
        }
    }
}
int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> op(4);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    // 초깃값: 가장 큰 값과 작은 값으로 설정
    int min_result = 1e9;
    int max_result = -1e9;

    backtrack(1, arr[0], arr, op, max_result, min_result);

    cout << max_result << "\n";
    cout << min_result << "\n";

    return 0;
}