#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;
signed main() {
  ifstream in("lecture6_exercise_w23.csv");
  if (!in) {
    cerr << "Cannot open file" << endl;
    return 1;
  }
  map<std::string, pair<string, int>> m;
  string line;
  istringstream iss;
  string name, id, token;
  int year;
  while (getline(in, line)) {
    iss.str(line);
    string token;

    getline(iss, name, ',');
    getline(iss, id, ',');
    getline(iss, token, ',');

    year = stoi(token); // convert string to int
    if (m.find(name) != m.end()) {
      cerr << "Duplicate name: " << name << endl;
      return 1;
    }
    m[name] = {id, year};
    // reset the error state
    iss.clear();
  }

  for (auto &[name, info] : m) {
    cout << name << " " << info.first << " " << info.second << endl;
  }
  return 0;
}