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

struct DictEntry {
  string original;
  string repr;

  bool operator==(const DictEntry &other) {
    return this->repr.compare(other.repr) == 0;
  }
};

void uncapitalize(string &word) {
  forn(i, word.length()) { word[i] = tolower(word[i]); }
}

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    DEBUG = true;
  }

  auto dict = vector<DictEntry>();
  while (true) {
    string word;
    cin >> word;
    debug cout << "Scanned " << word << endl;
    if (word.compare("#") == 0) {
      break;
    } else {
      string sorted_word = word;
      uncapitalize(sorted_word);
      sort(sorted_word.begin(), sorted_word.end());
      dict.push_back({word, sorted_word});

      debug cout << "Pushing: " << word << ", " << sorted_word << endl;
    }
  }

  map<string, vector<DictEntry>> counts;
  for (auto &entry : dict) {
    counts[entry.repr].push_back(entry);
  }

  vector<string> ananagrams;
  for (auto &kv : counts) {
    if(kv.second.size() == 1) {
      ananagrams.push_back(kv.second[0].original);
    }
  }

  sort(ananagrams.begin(), ananagrams.end(), [](const string &a, const string &b) {
    return a < b;
  });

  for(auto &str : ananagrams) {
    cout << str << endl;
  }

  return 0;
}
