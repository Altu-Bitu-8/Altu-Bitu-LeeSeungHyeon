
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void findLen(string& w, int k) {
    vector<int> pos[26];
    int min_len = INT_MAX, max_len = -1;

    // 각 문자 위치 저장
    for (int i = 0; i < w.size(); i++) {
        pos[w[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < 26; i++) {
        // k번 등장하지 않으면 넘어감.
        if (pos[i].size() < k) {
            continue;
        }
        for (int j = 0; j <= pos[i].size() - k; j++) {
            int len = pos[i][j + k - 1] - pos[i][j] + 1;
            min_len = min(min_len, len);
            max_len = max(max_len, len);
        }
    }
    if (max_len == -1) {
        cout << "-1\n";
    }
    else {
        cout << min_len << " " << max_len << "\n";
    }
}



int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string w;
        int k;

        getline(cin, w);
        cin >> k;
        cin.ignore();

        if (k > w.size()) {
            cout << "-1\n";
            continue;
        }

        findLen(w, k);
    }


    return 0;
}