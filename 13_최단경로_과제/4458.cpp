#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 거리 배열 초기화를 위한 매직넘버 (최대값을 설정하여 비교를 쉽게 함)
const int INF = 987654321;

vector<bool> visited; // 방문 여부를 저장하는 벡터

typedef pair<int, int> pi; // 우선순위 큐에서 사용할 pair (거리, 노드번호)

// 다익스트라 알고리즘을 이용해 최단 경로 비용을 계산하는 함수
// n : 그래프 크기 (nxn), graph : 그래프 데이터
int dijkstra(int n, const vector<vector<int>>& graph) {
    // 거리 배열 초기화 (모든 값: INF로 설정)
    vector<int> dist(n*n, INF);
    priority_queue<pi> pq; // 최소 힙 우선순위 큐 (음수 사용으로 정렬 반전)
    
    // 4방향 이동 (좌우상하)
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    // 시작 위치(좌상단)에서 초기 거리 설정 및 큐에 삽입
    dist[0] = graph[0][0];
    pq.push({0, 0});

    while (!pq.empty()) {
        int cur = pq.top().second; // 현재 노드의 인덱스 가져오기
        pq.pop();
        visited[cur] = true; // 방문 처리

        // 1차원 좌표를 2차원으로 변환
        int x = cur / n, y = cur % n;

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i], next = nx * n + ny;

            // 경계 체크 및 방문 여부 확인
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[next]) {
                continue;
            }

            // 더 짧은 경로가 발견되면 갱신
            if (dist[next] > dist[cur] + graph[nx][ny]) {
                dist[next] = dist[cur] + graph[nx][ny];
                
                // 우선순위 큐에 삽입 (-를 붙여 작은 값이 우선순위 높도록 설정)
                pq.push({-dist[next], next});
            }
        }
    }
    return dist[n*n-1]; // 목표 위치(우하단)의 최소 비용 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<vector<int>> graph;
    int cnt = 1; // 문제 번호 카운트

    // n=0이 입력되면 종료
    while (cin >> n && n) {
        // 입력받은 n 크기로 그래프 및 방문 벡터 초기화
        graph.assign(n, vector<int>(n, 0));
        visited.assign(n*n, false);

        // 그래프 입력 처리
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        // 다익스트라 알고리즘 실행 후 결과 저장
        int ans = dijkstra(n, graph);

        // 결과 출력 (문제 번호와 함께)
        cout << "Problem " + to_string(cnt++) + ": " + to_string(ans) << '\n';
    }
}
