#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// 문자열을 자릿수로 나누는 함수
stack<int> sepStr(const string& s) {
    stack<int> sStack;

    for (char digit : s) {
        sStack.push(digit - '0');
    }
    return sStack;
}

// 받은 문자열을 하나하나 자릿수로 맞추는 함수
string addNum(const string& a, const string& b) {

    stack<int> s1 = sepStr(a);
    stack<int> s2 = sepStr(b);

    stack<int> sResult;
    string result;

    int carry = 0;

    // 스택으로 자릿수별로 덧셈 수행
    while (!s1.empty() || !s2.empty()) {
        int sum = carry;
        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }
        // 자릿수
        carry = sum / 10;
        sResult.push(sum % 10);
    }

    // 마지막으로 남아있는 경우
    if (carry) {
        sResult.push(carry);
    }

    // 결과 스택을 문자열로 변환
    while (!sResult.empty()) {
        result += (sResult.top() + '0');
        sResult.pop();
    }

    return result;
}


int main() {
    string a, b;
    cin >> a >> b;
    cout << addNum(a, b) << "\n";

    return 0;
}
