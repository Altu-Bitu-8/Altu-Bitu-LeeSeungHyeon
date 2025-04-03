#include <iostream>
#include <vector>
using namespace std;

int solvedLen(int n, vector<int>& arr, vector<int>& dp) {
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	
	return ans;
}

int main() {
	
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int result = solvedLen(n, arr, dp);
	cout << result << "\n";

	return 0;
}