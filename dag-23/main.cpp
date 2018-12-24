#include <iostream>
#include <string>

using namespace std;

bool is_leap(int year) {
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main() {
  int answer = 0;

  int c1 [] = { 3,7,6,1,8,9,4,5,2 };
  int c2 [] = { 5,4,3,2,7,6,5,4,3,2 };

  string current;
  while (cin >> current) {
    int mm = stoi(current.substr(2,2));
    int gender = stoi(current.substr(8,1));

    // Skip validating males and non-August months
    if (gender % 2 != 0 || mm != 8) continue;

    int dd = stoi(current.substr(0,2));
    int yy = stoi(current.substr(4,2));

    // Validate date part (first 6 numbers)
    if (dd > 31) continue;
    if (mm > 12) continue;
    if (mm % 2 != 0 && dd == 31) continue; // odd months cant have 31 days
    if (mm == 2 && dd > 29 && is_leap(yy)) continue; // february cant have more than 29 days in leap years
    if (mm == 2 && dd > 28 && !is_leap(yy)) continue; // february cant have more than 28 days in non leap years

    // Generate correct first control number from dates
    int correct_c1 = 0;
    for (int i=0; i<10; i++) {
      correct_c1 += stoi(current.substr(i, 1)) * c1[i];
    }
    if (correct_c1 % 11 == 0) correct_c1 = 0;
    else if (correct_c1 % 11 == 1) continue;
    else correct_c1 = 11 - (correct_c1 % 11);

    // Validate first control number
    int control_number_1 = stoi(current.substr(9,1));
    if (control_number_1 != correct_c1) continue;

    // Generate correct second control number from dates
    int correct_c2 = 0;
    for (int i=0; i<9; i++) {
      correct_c2 += stoi(current.substr(i, 1)) * c2[i];
    }
    correct_c2 += correct_c1 * c2[9];
    if (correct_c2 % 11 == 0) correct_c2 = 0;
    else if (correct_c2 % 11 == 1) continue;
    else correct_c2 = 11 - (correct_c2 % 11);

    // Validate second control number
    int control_number_2 = stoi(current.substr(10,1));
    if (control_number_2 != correct_c2) continue;

    answer += 1;
  }
  cout << "Answer: " << answer << endl;
  return 0;
}
