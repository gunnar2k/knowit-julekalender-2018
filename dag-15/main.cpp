#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <math.h>

using namespace std;

string open(string filename) {
  string result;
  ifstream file (filename);
  if (file.is_open()) {
    char c;
    while (file.get(c)) {
      result += c;
    }
    file.close();
  }
  return result.substr(0, result.size()-1);
}

vector<int> get_birth_years(string input) {
  int dot_index = 0;
  istringstream iss(input);
  vector<int> result;
  for (string line; getline(iss, line); ) {
    dot_index = line.find(".");
    string year_str = line.substr(dot_index+1);
    int year = stoi(year_str);
    result.push_back(year);
  }
  return result;
}


int main() {
  string input = open("input-gullbursdag.txt");
  vector<int> years = get_birth_years(input);
  int answer = 0;
  for(int year : years) {
    for (int j=0; j<100; j++) {
      if (pow(j,2) == year+j) {
        answer += 1;
        break;
      }
    }
  }
  cout << answer << endl;
  return 0;
}
