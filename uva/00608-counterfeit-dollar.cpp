#include <iomanip>
#include <iostream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <utility>

#include <algorithm>

#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define ll long long
#define ld long double

#define ii pair<int, int>

#define vi vector<int>
#define vd vector<double>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vii vector<pair<int, int>>
#define vll vector<long long>

#define ses set<string>
#define sec set<char>
#define seb set<bool>
#define sei set<int>
#define seii set<pair<int, int>>
#define sell set<long long>

#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int, int>>>

#define mii map<int, int>
#define mid map<int, double>
#define mci map<char, int>
#define mic map<int, char>
#define msi map<string, int>
#define msvs map<string, vector<string>>
#define mcvc map<char, vector<char>>

#define stll stack<long long>

bool DEBUG = false;
#define debug if (DEBUG)

#define forn(karna, n) for (int karna = 0; karna < n; karna++)
#define ignore cin.ignore(1000, '\n')

#define EPS 1e-7

bool eq(double a, double b) { return abs(a - b) < EPS; }

template <typename T>
void print_collection(const T &collection, string title = "") {
  cout << title << ": ";
  for (auto &el : collection) {
    cout << el << ", ";
  }
  cout << endl;
}

class Line {
 public:
  string left_w;
  string right_w;
  string result;

  int sz() const { return left_w.size() + right_w.size(); }
};

void _remove_if_not_in(sec &fr, const string &wh) {
  vc for_removal;
  for (auto &c : fr) {
    if (wh.find(c) == string::npos) {
      for_removal.push_back(c);
    }
  }

  for (auto &c : for_removal) {
    fr.erase(c);
  }
}

void _remove_if_in(sec &fr, const string &wh) {
  vc for_removal;
  for (auto &c : fr) {
    if (wh.find(c) != string::npos) {
      for_removal.push_back(c);
    }
  }
  for (auto &c : for_removal) {
    fr.erase(c);
  }
}

void _remove_if_in(sec &fr, const sec &wh) {
  vc for_removal;
  for (auto &c : fr) {
    if (wh.find(c) != wh.end()) {
      for_removal.push_back(c);
    }
  }
  for (auto &c : for_removal) {
    fr.erase(c);
  }
}

bool is_in(const char &c, const sec &s) { return s.find(c) != s.end(); }
bool is_in(const char &c, const string &s) { return s.find(c) != string::npos; }

bool is_in_all(const char &c, const vector<Line> &lines) {
  for (auto &line : lines) {
    if (!is_in(c, line.left_w) && !is_in(c, line.right_w)) {
      return false;
    }
  }

  return true;
}

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    DEBUG = true;
  }

  int n;
  cin >> n;

  forn(i, n) {
    sec lighter, heavier, even, all;

    vector<Line> lines, up_lines, down_lines;
    forn(j, 3) {
      Line line;
      cin >> line.left_w >> line.right_w >> line.result;
      debug cout << "Scanned line: " << line.left_w << "|" << line.right_w
                 << "|" << line.result << endl;
      lines.push_back(line);
    }

    for (auto &line : lines) {
      debug cout << "\n\tProcessing " << line.left_w << "|" << line.right_w
                 << "|" << line.result << endl;
      string left_w = line.left_w, right_w = line.right_w, result = line.result;

      sec lighter_before(lighter), heavier_before(heavier);

      if (result.compare("up") == 0) {
        up_lines.push_back(line);
        for (auto &c : right_w) {
          lighter.insert(c);
          all.insert(c);
        }

        for (char &c : left_w) {
          heavier.insert(c);
          all.insert(c);
        }
      } else if (result.compare("down") == 0) {
        down_lines.push_back(line);
        for (char &c : right_w) {
          heavier.insert(c);
          all.insert(c);
        }

        for (char &c : left_w) {
          lighter.insert(c);
          all.insert(c);
        }
      } else if (result.compare("even") == 0) {
        for (char &c : right_w) {
          even.insert(c);
          all.insert(c);
        }

        for (char &c : left_w) {
          even.insert(c);
          all.insert(c);
        }
      }
    }

    sec candidates;
    for (auto &c : all) {
      if (!(is_in(c, lighter) && is_in(c, heavier)) && !is_in(c, even) &&
          is_in_all(c, up_lines) && is_in_all(c, down_lines)) {
        candidates.insert(c);
      }
    }

    debug print_collection(candidates, "\tcandidates");

    debug cout << string(30, '>') << "\t";
    if (candidates.size() == 1) {
      char candidate = *candidates.begin();
      cout << candidate;
      if (is_in(candidate, lighter)) {
        cout << " is the counterfeit coin and it is light." << endl;
      } else if (is_in(candidate, heavier)) {
        cout << " is the counterfeit coin and it is heavy." << endl;
      }
    }

    debug cout << endl << endl;
  }
  
  return 0;
}
