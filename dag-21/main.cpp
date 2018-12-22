#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> primes;
  long long int answer = 0;
  primes.push_back(2);
  for (int i=3; i < 10000000; i++) {
    bool prime=true;
    for (int j = 0; j < primes.size() && primes[j]*primes[j] <= i; j++) {
      if(i % primes[j] == 0) {
        prime=false;
        break;
      }
    }

    if (prime) {
      int last_prime = primes.back();
      if (i - last_prime == 2) {
        int candidate = i - 1;
        int sum = 0;
        for (int j = 1; j < candidate; j++) {
          if (candidate % j == 0) sum += j;
          if (sum > candidate) {
            answer += candidate;
            break;
          }
        }
      }
      primes.push_back(i);
    }
  }

  cout << answer << endl;

  return 0;
}
