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

template <typename T>
void print_vector(const vector<T> &vec) {
  for (auto v : vec) {
    cout << v << ", ";
  }
  cout << endl;
}

enum FrameType { NORMAL, STRIKE, SPARE };

struct Frame {
  FrameType type;
  int points;
  vc rolls;
};

string type_to_str(const FrameType &t) {
  switch (t) {
    case NORMAL:
      return "NORMAL";
    case STRIKE:
      return "STRIKE";
    case SPARE:
      return "SPARE";
  }
}

int to_points(char c) {
  if (c == 'X') {
    return 10;
  } else if (c == '/') {
    return 10;
  } else {
    return c - '0';
  }
}

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    DEBUG = true;
  }

#define MAX_ROLLS 24
  // forn(k, 10) {
  while (true) {
    vc rolls;
    vector<Frame> frames;

    string str;
    getline(cin, str, '\n');

    if (str.compare("Game Over") == 0) {
      break;
    }

    for (char c : str) {
      if (c != ' ') {
        rolls.push_back(c);
      }
    }

    debug print_vector(rolls);

    int curr = 0;
    int frame_total = 0;
    vc frame_rolls(2, '?');
    forn(i, rolls.size()) {
      frame_rolls[curr] = rolls[i];

      if (rolls[i] == '/') {
        frames.push_back({SPARE, 10, frame_rolls});

        frame_rolls = vc(2, '?');
        curr = 0;
        frame_total = 0;
      } else if (rolls[i] == 'X') {
        frames.push_back({STRIKE, 10, frame_rolls});

        frame_rolls = vc(2, '?');
        curr = 0;
        frame_total = 0;
      } else if (curr == 1 || i == rolls.size() - 1) {
        frame_total += rolls[i] - '0';
        frames.push_back({NORMAL, frame_total, frame_rolls});

        frame_rolls = vc(2, '?');
        frame_total = 0;
        curr = 0;
      } else {
        frame_total += rolls[i] - '0';
        curr++;
      }
    }

    debug cout << "frames size " << frames.size() << endl;

    int total = 0;
    forn(i, 10) {
      int prev_total = total;
      auto f = frames[i];
      debug cout << type_to_str(f.type) << " [" << f.points << "]"
                 << " {" << f.rolls[0] << " " << f.rolls[1] << "}"
                 << ", " << endl;

      if (f.type == NORMAL) {
        debug cout << "\tAdding normal points " << f.points << " for frame "
                   << i << endl;
        total += f.points;
      } else if (f.type == STRIKE) {
        debug cout << "\tAdding strike points 10 for frame " << i << endl;
        total += 10;
        if (frames[i + 1].type == SPARE) {
          debug cout << "\tAdding first and second strike bonus =" << 10
                     << " for frame " << i << endl;
          total += 10;
        } else if (frames[i + 1].type == STRIKE) {
          debug cout << "\tAdding first strike bonus =" << 10 << " for frame "
                     << i << endl;
          total += 10;

          if (i + 2 < frames.size()) {
            int points = to_points(frames[i + 2].rolls[0]);

            debug cout << "\tAdding second strike bonus =" << points
                       << " for frame " << i << endl;

            total += points;
          }

        } else {
          debug cout << "\tAdding first and second strike bonus =" << frames[i + 1].points
                     << " for frame " << i << endl;
          total += frames[i + 1].points;
        }
      } else if (f.type == SPARE) {
        total += 10;
        debug cout << "\tAdding points =" << 10 << " for frame "
                   << i << endl;
        
        if(i + 1 < frames.size()) {
          if (frames[i + 1].type == STRIKE) {
            debug cout << "\tAdding bonus =" << 10 << " for frame "
                    << i << endl;
            total += 10;
          } else {
            debug cout << "\tAdding roll bonus =" << frames[i + 1].rolls[0] - '0' << " for frame "
                    << i << endl;
            total += frames[i + 1].rolls[0] - '0';
          }
        }
      }

      debug cout << '\t' << string(5, '=') << " Total for frame " << i << " is " << 
        total - prev_total << endl << endl;
    }

    cout << total << endl;

    debug cout << endl << endl;
  }

  return 0;
}
