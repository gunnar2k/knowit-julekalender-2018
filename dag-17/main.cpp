#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

struct Point {
  int x, y;

  Point(int a, int b) {
    this->x = a;
    this->y = b;
  }
};

vector <Point> points;

float distance(Point a, Point b) {
  return sqrt(pow((b.x - a.x), 2) + pow(b.y - a.y, 2));
}

int main() {
  auto begin = chrono::high_resolution_clock::now();

  // Get the points from the input
  ifstream file("input.txt");
  string line;
  while (getline(file, line)) {
    size_t found = line.find(",");
    float x = stof(line.substr(0, found));
    float y = stof(line.substr(found+1));
    points.push_back(Point(x,y));
  }
  file.close();

  // Generate adjacency matrix for distances
  float adj[points.size()][points.size()];
  for (int i=0; i<points.size(); i++) {
    for (int j=0; j<points.size(); j++) {
      if (i == j) continue;
      adj[i][j] = distance(points[i], points[j]);
    }
  }

  // Use hamiltonian cycle path to find solution
  float shortest = 100000000.0;
  for (int i=0; i < points.size(); i++) {
    vector<int> vertex;
    for (int j = 0; j < points.size(); j++)
      if (i != j)
        vertex.push_back(j);

    while (next_permutation(vertex.begin(), vertex.end())) {
      float path_length = 0;
      int k = i;
      for (int j = 0; j < vertex.size(); j++) {
        path_length += adj[k][vertex[j]];
        k = vertex[j];
      }

      if (path_length < shortest)
        shortest = path_length;
    }
  }

  cout << "Answer:" << round(shortest) << endl;

  auto end = chrono::high_resolution_clock::now();
  cout << chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms" << endl;

  return 0;
}
