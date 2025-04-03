#include <iostream>
#include <vector>
using namespace std;

int solvedMod(int n, vector<int> &dp) {
	int ans = 0;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	return dp[n] % 10007;
}

int main() {
	
	int n;
	cin >> n;

	// 벡터 크기 확보하기
	int size = (n < 3) ? 3 : n + 1;
	//2*n 크기 채우는 경우의 수 dp
	vector<int> dp(size);
	cout << solvedMod(n,dp) << "\n";

	return 0;
}