#include <iostream>
#include <cmath>

using namespace std;

// 최대공약수를 이용합니다.
int gcb(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main()
{
    int n, s;
    cin >> n >> s;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = abs(s - a[0]);

    for (int i = 1; i < n; i++) {
        result = gcb(result, abs(s - a[i]));
    }
    cout << result << "\n";

    return 0;
}