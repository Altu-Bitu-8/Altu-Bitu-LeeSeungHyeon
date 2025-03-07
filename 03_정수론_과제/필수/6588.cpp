#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 소수 판별 함수
void find_Primes(vector<bool>& is_prime, int limit) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= limit; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i <= sqrt(limit); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// 골드바흐의 추측을 검증하는 함수
void goldbach_Conjecture(int n, const vector<bool>& primes) {
    for (int a = 3; a <= n / 2; a += 2) {
        if (primes[a] && primes[n - a]) {
            cout << n << " = " << a << " + " << (n - a) << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int limit = 1000000;
    vector<bool> is_prime(limit + 1, true);
    find_Primes(is_prime, limit);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        goldbach_Conjecture(n, is_prime);
    }

    return 0;
}