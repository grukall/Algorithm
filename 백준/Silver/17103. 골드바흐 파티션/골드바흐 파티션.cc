#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_num; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= max_num; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int countGoldbachPairs(int num, const vector<int>& primes) {
    int left = 0, right = primes.size() - 1;
    int count = 0;

    while (left <= right) {
        int sum = primes[left] + primes[right];
        if (sum == num) {
            //cout << num << " case : {" << primes[left] << ", " << primes[right] << "}\n";
            count++;
            left++;
            right--;
        } else if (sum < num) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    vector<int> test_cases(t);
    int max_testcase = 0;

	//가장 큰 케이스를 찾는 코드 추가
    for (int i = 0; i < t; i++) {
        cin >> test_cases[i];
        max_testcase = max(max_testcase, test_cases[i]);
    }

	//가장 큰 케이스에 맞추어 소수 목록 구하기기
    vector<int> primes = sieve(max_testcase);

    for (int testcase : test_cases) {
        // cout << "Testcase " << testcase << ", 소수 개수: " << primes.size() << "\n";
        // cout << testcase << "보다 작은 소수 목록: ";
        
        // for (int prime : primes) {
        //     if (prime >= testcase) break;
        //     cout << prime << " ";
        // }
        // cout << "\n";

        int count = countGoldbachPairs(testcase, primes);
        cout << count << "\n";
    }

    return 0;
}
