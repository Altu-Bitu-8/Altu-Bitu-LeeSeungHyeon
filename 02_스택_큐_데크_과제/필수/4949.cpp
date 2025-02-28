#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool cmp(const string& se) {
    stack<char> s;

    for (char c : se) {
        if (c == '(' || c == '[') {
            s.push(c);
        }
        else if (c == ')') {
            if (s.empty() || s.top() != '(') return false;
            s.pop();
        }
        else if (c == ']') {
            if (s.empty() || s.top() != '[') return false;
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string se;

    while (true) {
        getline(cin, se);
        if (se == ".") break;
        cout << (cmp(se) ? "yes" : "no") << endl;
    }

    return 0;
}