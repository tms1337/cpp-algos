#include <iostream>
#include <iomanip>

#include <cmath>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdio>

#include <algorithm>

#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define ll long long
#define ii pair<int, int>

#define vi vector<int>
#define vd vector<double>
#define vb vector<bool>

#define seb set<bool>
#define sei set<int>
#define seii set< pair<int, int> >
#define sell set<long long>

#define vvb vector< vector<bool> >
#define vvi vector< vector<int> >

#define mii map<int, int>
#define mid map<int, double>

#define stll stack<long long>

#define DEBUG 1
#define debug if(DEBUG)

#define loop(karna, n) for(int karna = 0; karna < n; karna++)

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
	for(int i = 0; i < v.size(); i++) {
		os << v[i] << " ";
	}

	return os;
}

template<typename U, typename V>
ostream& operator<<(ostream &os, const pair<U, V> &p) {
    os << "(" << p->first << ", " << ")" << p->second;

    return os;
}

double get_time() {
	return clock() / (1.0 * CLOCKS_PER_SEC);
}

bool eq(double a, double b) {
    static double EPS = 1e-5;

    return fabs(a - b) < EPS;
}

template<typename T>
bool all_same(const vector<T> &v) {
	if(v.size() == 0) {
		return true;
	}

	for(int i = 1; i < v.size(); i++) {
		if(v[i] != v[0]) {
			return false;
		}
	}

	return true;
}

struct point {
    double x;
    double y;
    double z;

    point(double x, double y) {
        this->x = x;
        this->y = y;
        this->z = 0;
    }

    point(double x, double y, double z) {
    	this->x = x;
        this->y = y;
        this->z = z;
    }
};

double dist(const point &A, const point &B) {
    return sqrt( 
        (A.x - B.x) * (A.x - B.x) + 
        (A.y - B.y) * (A.y - B.y) +
        (A.z - B.z) * (A.z - B.z)
    );
}

// ==== LINE ====

string input_file = ".in";
string output_file = ".out";

struct solution {
	int up;
	int down;
	int by_pref;
};

solution sol;

vb prefs;
bool init_state;

#define UP true
#define DOWN false

void read_data() {
	string line;
	getline(cin, line);

	// U = up = true
	init_state = (line[0] == 'U');

	for(int i = 1; i < line.size(); i++) {
		prefs.push_back(line[i] == 'U');
	}

	sol.up = sol.down = sol.by_pref = 0;
}

void eval_by_pref() {
	bool state = init_state;
	for(int i = 0; i < prefs.size(); i++) {
		if(prefs[i] != state) {
			sol.by_pref++;
		}

		state = prefs[i];

		if(prefs[i] != state) {
			sol.by_pref++;
		}
	}
}

void eval_down() {
	bool state = init_state;
	for(int i = 0; i < prefs.size(); i++) {
		if(prefs[i] != state) {
			sol.down++;
		}

		state = DOWN;

		if(prefs[i] != state) {
			sol.down++;
		}
	}
}

void eval_up() {
	bool state = init_state;
	for(int i = 0; i < prefs.size(); i++) {
		if(prefs[i] != state) {
			sol.up++;
		}

		state = UP;

		if(prefs[i] != state) {
			sol.up++;
		}
	}
}

void solve() {
    eval_up();
    eval_down();
    eval_by_pref();
}

void write_solution() {
	cout << sol.up << endl << sol.down << endl <<
		sol.by_pref << endl;
}

void run() {
    read_data();
    solve();
    write_solution();
}

int main(int argc, char **argv) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

	run();

	return 0;
}