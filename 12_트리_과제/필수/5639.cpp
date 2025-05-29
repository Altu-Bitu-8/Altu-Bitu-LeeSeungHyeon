
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    // 노드 초기화
    Node(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    // 빈 노드라면 새 노드 생성
    if (!root) {
        return new Node(val);
    }

    // 왼쪽
    if (val < root->val) {
        root->left = insert(root->left, val);
    }
    // 오른쪽
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

// 후위 순회
void postorder(Node* root) {
    if (!root) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << "\n";
}
int main()
{
    Node* root = nullptr;
    int val;

    while (cin >> val) {
        root = insert(root, val);
    }

    postorder(root);
    return 0;
}