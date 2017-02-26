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
#define ld long double
#define ii pair<int, int>

#define vi vector<int>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vii vector< pair<int, int> >

#define seb set<bool>
#define sei set<int>
#define seii set< pair<int, int> >
#define sell set<long long>

#define vvb vector< vector<bool> >
#define vvi vector< vector<int> >
#define vvii vector< vector< pair<int, int> > >

#define mii map<int, int>
#define mid map<int, double>

#define stll stack<long long>

#define DEBUG 0
#define debug if(DEBUG)

#define forn(karna, n) for(int karna = 0; karna < n; karna++)
#define ignore cin.ignore(1000, '\n')

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
	vvii stats; 
};

solution sol;

int get_move_code(const string &x) {
	if(x == "rock") {
		return 0;
	} else if(x == "paper") {
		return 1;
	} else if(x == "scissors") {
		return 2;
	}

	throw;
}

bool is_better_move(const string &a, const string &b) {
	int move_code_a = get_move_code(a);
	int move_code_b = get_move_code(b);

	if(move_code_a == 0 && move_code_b == 1) {
		return true;
	} else if(move_code_a == 1 && move_code_b == 2) {
		return true;
	} else if(move_code_a == 2 && move_code_b == 0) {
		return true;
	} else {
		return false;
	}
}

void read_data() {
	int n, k;

	int it = 0;
	
	while(true) {
		cin >> n;

		if(n == 0) {
			break;
		}

		cin >> k;
		
		sol.stats.push_back(vii(n, make_pair(0, 0)));

		forn(i, k * n * (n - 1) / 2) {
			int p_first, p_second;
			string move_first, move_second;

			cin >> p_first >> move_first >> 
				 p_second >> move_second;

			p_first--;
			p_second--;

			if(move_first != move_second) {
				if(is_better_move(move_first, move_second)) {
					sol.stats[it][p_first].first++;
					sol.stats[it][p_second].second++;
				} else {
					sol.stats[it][p_second].first++;
					sol.stats[it][p_first].second++;
				}
			}
		}

		it++;
	}
}

void solve() {
    
}

void write_solution() {
	forn(i, sol.stats.size()) {
		forn(j, sol.stats[i].size()) {
			if(sol.stats[i][j].first == 0 && sol.stats[i][j].second == 0) {
				printf("-\n");
			} else {
				double avg = 
					(double)sol.stats[i][j].second / 
					(sol.stats[i][j].first + sol.stats[i][j].second);

				printf("%.3lf\n", avg);
			}

			
		}

		if(i != sol.stats.size() - 1) {
			cout << endl;
		}
	}
}

void run() {
    read_data();
    solve();
    write_solution();
}

int main(int argc, char **argv) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    debug cout << is_better_move("rock", "scissors") << endl;

	run();

	return 0;
}