#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
  // Start timer
  auto begin = std::chrono::high_resolution_clock::now();

  vector <char> log; // This will store the game log

  map <char, char> defeats;
  defeats['P'] = 'S';
  defeats['S'] = 'R';
  defeats['R'] = 'P';

  // Read input
  ifstream file("input-rpslog.txt");
  char c;
  while (file.get(c)) {
    if (c == '\n') {
      break;
    }
    log.push_back(c);
  }
  file.close();

  int final_score [3] = { 0, 0, 0 };
  while(!log.empty()) {
    // At the start of each game, get the three first hands in the game log
    char hands [3] = { log[0], log[1], log[2] };
    log.erase(log.begin(), log.begin()+3);

    // Skip to next game if all hands are different (e.g RSP)
    // or if all hands are the same (e.g RRR)
    if (
      (hands[0] != hands[1] && hands[0] != hands[2] && hands[1] != hands[2]) ||
      (hands[0] == hands[1] && hands[0] == hands[2] && hands[1] == hands[2])
    ) continue;

    bool rematch = true;
    vector <int> rm_between;

    // Iterate all player hands and see which ones wins the games
    for (int i = 0; i < 3; i++) {
      int win_count = 0;

      for (int j = 0; j < 3; j++) {
        if (i == j) continue; // Skip playing self
        if (hands[i] == defeats[hands[j]]) win_count++;
      }

      // When a player defeats the other 2 players, he winss
      if (win_count == 2) {
        final_score[i]++;
        rematch = false;
        break;
      }

      // If a player defeats just one other player, there might get a rematch
      if (win_count == 1) {
        rm_between.push_back(i);
      }
    }

    // If rematch is declared, keep playing until one wins
    while(rematch) {
      char rm_hands [2] = { log[0], log[1] };
      log.erase(log.begin(), log.begin()+2);

      // Player 1 of the current rematch wins
      if (rm_hands[0] == defeats[rm_hands[1]]) {
        final_score[rm_between[0]]++;
        rematch = false;
      }
      // Player 2 of the current rematch wins
      else if (rm_hands[1] == defeats[rm_hands[0]]) {
        final_score[rm_between[1]]++;
        rematch = false;
      }
      // Still a tie, keep rematching
      else {
        continue;
      }
    }
  }

  cout << final_score[0] << "," << final_score[1] << "," << final_score[2] << endl;

  // End timer
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << "us" << std::endl;

  return 0;
}
