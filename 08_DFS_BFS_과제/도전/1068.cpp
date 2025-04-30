#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree; // 트리의 인접 리스트
vector<bool> visited;     // 방문 여부를 저장하는 배열
int answer = 0;           // 리프 노드 개수를 세는 변수
int root, deletenode;     // 루트 노드와 삭제할 노드

void dfs(int number) {
    visited[number] = true;
    int childcnt = 0;

    for (int i : tree[number]) {
        if (!visited[i] && i != deletenode) {
            childcnt++;
            dfs(i);
        }
    }

    if (childcnt == 0) {
        answer++;
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n);       // 트리의 크기를 설정
    visited.resize(n);    // 방문 배열의 크기를 설정

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] != -1) {
            tree[i].push_back(p[i]);
            tree[p[i]].push_back(i);
        }
        else {
            root = i;
        }
    }

    cin >> deletenode;

    if (deletenode == root) {
        cout << 0 << "\n";
    }
    else {
        dfs(root);
        cout << answer << "\n";
    }

    return 0;
}