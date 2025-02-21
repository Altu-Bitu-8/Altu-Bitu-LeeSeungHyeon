
// 시리얼 번호

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc_Sum(const string& serial) {
	int sum = 0;
	for (int i = 0; i < serial.size(); i++) {
		if (isdigit(serial[i])) {
			sum += serial[i] - '0';
		}
	}
	return sum;
}

bool cmp(const string& A, const string& B) {
	// 1번 조건
	if (A.size() != B.size()) {
		return A.size() < B.size();
	}
	// 2번 조건
	int sum_A = calc_Sum(A);
	int sum_B = calc_Sum(B);
	if (sum_A != sum_B) {
		return sum_A < sum_B;
	}
	// 3번 조건
	return A < B;
}

int main() {
	int n;
	cin >> n;

	vector<string> serials(n);

	for (int i = 0; i < n; i++) {
		cin >> serials[i];
	}

	sort(serials.begin(), serials.end(), cmp);

	for (int i = 0; i < serials.size(); i++) {
		cout << serials[i] << endl;
	}

	return 0;
}