#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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


int main()
{
   int n; cin >> n;
   if (n <= 1)
   {
     cout << 0;
     return 0;
   }
   else if (n == 2)
   {
     cout << 1;
     return 0;
   }
   //1. 2~n 사이의 소수 목록을 구해야 한다.
   //소수 구하는 방법 : 에라스뭐시기의 체
   //

   vector<int> decimals = sieve(n);

   int start = 0, end = 1;
   int sum = decimals[0] + decimals[1];
   int Count = 0;
   while (start <= end)
   {
     if  (sum == n)
     {
         // printf("sum = %d, count = %d\n", sum, Count);
          Count++;
          end++;
          if (end == decimals.size()) break;
          sum += decimals[end];
     }
     else if (sum > n)
     {
         // printf("sum = %d, start++\n", sum);
          sum -= decimals[start];
          start++;
     }
     else
     {
         // printf("sum = %d, end++\n", sum);
          end++;
          if (end == decimals.size()) break;
          sum += decimals[end];
     }
   }

   cout << Count;
   
}