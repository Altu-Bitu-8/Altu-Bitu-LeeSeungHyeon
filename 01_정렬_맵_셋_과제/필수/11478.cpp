
// 서로 다른 부분 문자열의 개수

#include <iostream>
#include <set>
#include <string>

using namespace std;

int solved(string s) {
	int ans = 0;
	set<string> substrings;

	for (int i = 0; i < s.size(); ++i) {
		for (int j = 1; j <= s.size() - i; j++) {
			substrings.insert(s.substr(i, j));
		}
	}

	ans = substrings.size();
	return ans;
}

int main() {
	string s;
	cin >> s;
	cout << solved(s) << endl;
}