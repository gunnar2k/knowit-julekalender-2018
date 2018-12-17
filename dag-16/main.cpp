#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> input() {
  ifstream input("input-palindrom.txt");
  vector<int> result;
  char c;
  char comma = *",";
  int nr;
  while (input.get(c)) {
    if (c == comma) {
      continue;
    }
    nr = (int(c) - 48);
    if (nr != -38) {
      result.push_back(nr);
    }
  }
  input.close();
  return result;
}

bool is_prime(int num) {
  for(int i = 2; i <= num / 2; ++i) {
    if(num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> numbers = input();
  int answer = 0;
  for (int i=0; i<numbers.size(); i++) {
    if (numbers[i] % 2 == 0) {
      continue;
    }
    int sum = numbers[i];
    for (int j=1; j<numbers.size()/2; j++) {
      if (i-j < 0)
        break;

      if (i+j > numbers.size()/2)
        break;

      int a = numbers[i-j];
      int b = numbers[i+j];

      if (a != b)
        break;

      sum += a + b;

      if (is_prime(sum) && sum > answer) {
        answer = sum;
      }
    }
  }
  cout << "Answer: " << answer << endl;
  return 0;
}
