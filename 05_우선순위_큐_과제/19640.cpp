#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 사람의 정보를 저장하는 구조체
struct info {
    int idx;   // 처음 줄에 선 번호
    int line_num;   // m개의 줄 중 속한 줄 번호
    int work_days;  // 근무 일수
    int urgency;    // 급한 정도
};

// 우선순위를 결정하는 비교 연산자 구조체
struct cmp {
    bool operator()(const info& child, const info& parent) {
        // 1. 근무 일자가 많은 사람이 우선
        if (parent.work_days != child.work_days) {
            return parent.work_days > child.work_days;
        }
        // 2. 근무 일수가 같다면, 더 급한 사람이 우선
        if (parent.urgency != child.urgency) {
            return parent.urgency > child.urgency;
        }
        // 3. 급한 정도가 같다면, 줄 번호가 앞선 사람이 우선
        return parent.line_num < child.line_num;
    }
};

// 화장실 이용 시뮬레이션 함수
int simulation(int m, int k, vector<queue<info>>& lines) {
    // 우선순위 큐
    priority_queue<info, vector<info>, cmp> pq;

    // 각 줄의 첫 번째 사람을 우선순위 큐에 추가
    for (int i = 0; i < m; i++) {
        if (!lines[i].empty()) { // 해당 줄이 비어있지 않을 경우에만
            pq.push(lines[i].front()); // 줄의 선두를 우선순위 큐에 추가
            lines[i].pop(); // 큐에서 선두를 제거
        }
    }

    // k번째 사람의 차례가 오기 전까지 카운트
    int count = 0;

    // 우선순위 큐가 비어 있지 않고, 아직 k의 차례가 아닌 경우 반복
    while (!pq.empty() && pq.top().idx != k) {
        // 화장실을 사용한 사람의 줄 번호
        int line_num = pq.top().line_num; 
        // 우선순위가 가장 높은 사람 제거.
        pq.pop(); 

        // 해당 줄의 다음 사람을 우선순위 큐에 추가
        if (!lines[line_num].empty()) {
            pq.push(lines[line_num].front());
            lines[line_num].pop();
        }
        // 화장실을 사용한 사람 수 증가
        count++; 
    }
    // k번째 사람이 화장실을 사용하기 전까지의 인원 수 반환
    return count; 
}

int main() { 
    // 입력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 총 사람 수, 줄의 개수, 데카의 인덱스 입력
    int n, m, k, d, h;
    cin >> n >> m >> k; 
    
    // m개의 줄을 생성
    vector<queue<info>> lines(m, queue<info>()); 

    // 각 사람의 정보를 입력받아 줄에 추가
    for (int i = 0; i < n; i++) {
        // 근무 일수(d), 급한 정도(h) 입력
        cin >> d >> h; 
        // (온 순서 % m)번째 줄에 추가
        lines[i % m].push({ i, i % m, d, h }); 
    }

    // 시뮬레이션 실행 및 결과 출력
    cout << simulation(m, k, lines);

    return 0;
}
