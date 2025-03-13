#include <iostream>

using namespace std;
int main()
{
    // 입력
    int e, s, m;
    cin >> e >> s >> m;
    int year = 1;

    // 나머지 연산
    while (true) {
        if ((year - 1) % 15 + 1 == e && (year - 1) % 28 + 1 == s && (year - 1) % 19 + 1 == m)
        {
            break;
        }
        year++;
    }

    cout << year << "\n";
    return 0;
}