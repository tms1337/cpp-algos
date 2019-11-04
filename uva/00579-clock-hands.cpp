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

double to_mod(double a, double m, double full = 360) {
  if (full - a < a) {
    return full - a;
  }
  debug cout << "mod " << a << ", " << m << endl;
  return a - floor(a / m) * m;
}

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    DEBUG = true;
  }

  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(3);

  while (true) {
    int h, m;
    if (scanf("%d:%d", &h, &m) != 2) {
      break;
    }

    if (h == 0 && m == 0) {
      break;
    }

    double m_part = (double)m / 60;
    double m_degree = m_part * 360;
    double h_degree = ((double)h / 12 + m_part / 12) * 360;

    // double degree = abs(h_degree - m_degree);
    double degree = to_mod(abs(h_degree - m_degree), 180);

    debug cout << "Input line " << h << ":" << m << endl;
    debug cout << "h_degree = " << h_degree << ", m_degree = " << m_degree
               << ", degree = " << degree << endl;
    debug cout << endl;

    if (h == 12 && m == 0) {
      cout << 0.0 << endl;
    } else if (h == 6 && m == 0) {
      cout << 180.0 << endl;
    } else {
      cout << degree << endl;
    }
  }

  return 0;
}
