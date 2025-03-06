#include <iostream>
#include <queue>

using namespace std;

int main() {

	int n;
	cin >> n;


	queue<int> q;

	// 1부터 n까지 
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	// 위에 있는 원소를 버리고,
	// 제일 위에 있는 카드를 카드밑으로 옮긴다.
	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	// 남아있는 원소 출력
	if (!q.empty()) {
		cout << q.front();
	}
	return 0;
}