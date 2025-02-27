# ÆÐ¼Ç¿Õ ½ÅÇØºó


#include <iostream>
#include <map>

using namespace std;

int combinations(int n) {
    map<string, int> clothes;
    for (int i = 0; i < n; i++) {
        string name, type;
        cin >> name >> type;
        clothes[type]++;
    }
    int answer = 1;
    for (auto& c : clothes) {
        answer *= (c.second + 1);
    }
    return answer - 1;
}

int main() {
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        int n;
        cin >> n;
        cout << combinations(n) << endl;
    }

    return 0;
}