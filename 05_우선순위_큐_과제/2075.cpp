#include <iostream>
#include <queue>
using namespace std;

// 우선순위 큐 업데이트 함수
void updateNum(priority_queue<int, vector<int>, greater<int>>& pq, int num, int max) {
    pq.push(num);
    if (pq.size() > max) {
        pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            updateNum(pq, num, n);
        }
    }
    // N번째로 큰 수 출력
    cout << pq.top() << "\n";
    return 0;
}