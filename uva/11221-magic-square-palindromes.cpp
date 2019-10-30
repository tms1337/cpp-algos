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

const string TRIMMED_CHARS = ",.?!() ";

string trim(const string &str) {
  string trimmed_str = "";

  for (const char c : str) {
    if (TRIMMED_CHARS.find(c) == string::npos) {
      trimmed_str += c;
    }
  }

  return trimmed_str;
}

int max_square_size(const string &str) { return int(ceil(sqrt(str.length()))); }

char get_char_in_dir(const string &sentence, int i, int k, int dir) {
  int len = sentence.length();
  int row, col;
  if (dir == 0) {
    return sentence[i];
  } else if (dir == 1) {
    row = i % k;
    col = int(i/k);
  } else if (dir == 2) {
    return sentence[len - 1 - i];
  } else if (dir == 3) {
    row = (k - 1 - (i % k) );
    col = k - 1 - int(i / k);
  } else {
    throw "Invalid dir argument";
  } 

  debug cout << "\trow, col " << row << " " << col << endl;
  
  return sentence[ row*k + col ];
}

bool is_magic(const string &sentence, int k) {
  forn(i, k) {
    char dirs[4] = {'?', '?', '?', '?'};
    forn(dir, 4) {
      debug cout << "Doing dir " << dir << endl;
      dirs[dir] = get_char_in_dir(sentence, i, k, dir);
    }

    if (dirs[0] != dirs[1] || dirs[0] != dirs[2] || dirs[0] != dirs[3]) {
      debug cout << "No match at " << i << endl;
      debug cout << "[" << dirs[0] << ", " << dirs[1] << ", " << dirs[2] << ", "
                 << dirs[3] << "]" << endl;
      return false;
    }
  }

  return true;
}

int is_magic(const string &sentence) {
  string trimmed_sentence = trim(sentence);

  int len = trimmed_sentence.length();
  double len_sqrt = sqrt(len);
  int mx = int(sqrt(len));
  debug cout << "len_sqrt, mx " << len_sqrt << " ," << mx << endl;
  if (!eq(len_sqrt, mx)) {
    debug cout << "Dimensions not ok" << endl;
    return -1;
  }

  if(is_magic(trimmed_sentence, mx)) {
    return mx;
  } else {
    return -1;
  }
}

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    DEBUG = true;
    cout << "Debugging" << endl;
  }

  int n;
  scanf("%d\n", &n);

  forn(i, n) {
    string sentence;
    getline(cin, sentence, '\n');

    debug cout << i << " : " << sentence << endl;

    int magic = is_magic(sentence);

    cout << "Case #" << i + 1 << ":" << endl;
    if (magic == -1) {
      cout << "No magic :(" << endl;
    } else {
      cout << magic << endl;
    }
    debug cout << endl;
  }

  return 0;
}
