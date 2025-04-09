#include <iostream>
#include <vector>
using namespace std;

int solvedMod(int n) {
    const int MODNUM = 10007;  
    vector<int> dp(n + 1);     
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MODNUM;  // MODNUM으로 나누기
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << solvedMod(n) << "\n";
    return 0;
}
