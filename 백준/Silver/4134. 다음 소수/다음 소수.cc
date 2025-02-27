#include <iostream>
#include <cmath>

using namespace std;

// 소수 판별 함수
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // 6k ± 1 소수 판별법
    long long sqrt_n = sqrt(n);
    for (long long i = 5; i <= sqrt_n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// n 이상의 가장 작은 소수 찾기
long long next_prime(long long n) {
    if (n <= 2) return 2;
    if (n % 2 == 0) n++;  // 짝수면 홀수로 변경

    while (!is_prime(n)) {
        n += 2;  // 홀수만 검사
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        cout << next_prime(n) << '\n';
    }

    return 0;
}
