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

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    DEBUG = true;
  }

  int N;
  scanf("%d\n", &N);

  debug cout << "Test cases " << N << endl;

  forn(i, N) {
    char figure;
    int m, n;
    scanf("%c %d %d\n", &figure, &m, &n);

    debug cout << "Figure is " << figure << endl;

    int max_figures;
    if (figure == 'r') {
      max_figures = min(m, n);
    } else if (figure == 'k') {
      int first = ceil((double)n / 2) * ceil((double)m / 2) +
                  floor((double)n / 2) * (m - ceil((double)m / 2));
      int second = ceil((double)m / 2) * ceil((double)n / 2) +
                  floor((double)m / 2) * (n - ceil((double)n / 2));

      max_figures = max(first, second);
    } else if (figure == 'Q') {
      max_figures = min(m, n);
    } else if (figure == 'K') {
      max_figures = ceil((double)m / 2) * ceil((double)n / 2);
    }

    cout << max_figures << endl;
  }

  return 0;
}
