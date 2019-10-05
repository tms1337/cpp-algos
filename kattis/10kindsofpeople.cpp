#include <iostream>
#include <iomanip>

#include <cmath>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <cstring>

#include <algorithm>

#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define ll long long
#define ld long double

#define ii pair<int, int>

#define vi vector<int>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vii vector< pair<int, int> >
#define vll vector<long long>

#define seb set<bool>
#define sei set<int>
#define seii set< pair<int, int> >
#define sell set<long long>

#define vvb vector< vector<bool> >
#define vvi vector< vector<int> >
#define vvii vector< vector< pair<int, int> > >

#define mii map<int, int>
#define mid map<int, double>
#define mci map<char, int>
#define mic map<int, char>
#define msi map<string, int>

#define stll stack<long long>

#define DEBUG 1
#define debug if(DEBUG)

#define forn(karna, n) for (int karna = 0; karna < n; karna++)
#define ignore cin.ignore(1000, '\n')

string choose_clusters(const string &row) {
  return row;
}

int tob(const string &s) {
  return stoi(s.c_str, nullptr, 2);
}

int main() {
  int r, c;
  scanf("%d %d", &r, &c);

  vs world_map(r);

  forn(i, r) {
    string row;
    cin >> row;
    world_map.push_back( row );
  }

  int n;
  scanf("%d", &n);

  forn(i, n) {
    int fx, fy, tx, ty;
    scanf("%d %d %d %d", &fx, &fy, &tx, &ty);

    // sort in order
    if(fx >= tx) {
      int tempx = tx;
      int tempy = ty;

      tx = fx;
      ty = fy;

      fx = tempx;
      fy = tempy;
    }

    fx--; fy--; tx--; ty--;

    string current = world_map[fx];
    for(int i = fx; i < fy; i++) {
      current = tob(choose_clusters(current, i));
    }
  }

  return 0;
}