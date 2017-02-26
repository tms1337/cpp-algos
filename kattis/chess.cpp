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
    os << "(" << p.first << ", " << p.second << ")";

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

    point() {
        this->x = this->y = this->z = 0.0;
    }

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

    bool operator==(const point &p) {
    	return 
    		eq(this->x, p.x) &&
    		eq(this->y, p.y) &&
    		eq(this->z, p.z);
    }

    bool operator!=(const point &p) {
    	return !(*this == p);
    }
};

double dist(const point &A, const point &B) {
    return sqrt( 
        (A.x - B.x) * (A.x - B.x) + 
        (A.y - B.y) * (A.y - B.y) +
        (A.z - B.z) * (A.z - B.z)
    );
}

ostream& operator<<(ostream &os, const point &p) {
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";

    return os;
}

#define pp pair<point, point>
#define vp vector<point>
#define vpp vector< pair<point, point> >

// ==== LINE ====

string input_file = ".in";
string output_file = ".out";

struct solution {
	vector<vp> moves;
};

solution sol;

vpp input;

void read_data() {
	mci cols;
	for(char c = 'A'; c <= 'H'; c++) {
		cols[c] = c - 'A';
	}

	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		char col;
		int row;

		point start, finish;

		cin >> col >> row;
		start.x = cols[col];
		start.y = row - 1;

		cin >> col >> row;
		finish.x = cols[col];
		finish.y = row - 1;

		input.push_back(make_pair(start, finish));
	}
}

bool is_same_color(const point &A, const point &B) {
	return ( (int)(A.x + A.y) % 2 == (int)(B.x + B.y) % 2 );
}

bool is_valid(const point &p) {
	return p.x >= 0 && p.x <= 7 && 
		p.y >= 0 && p.y <= 7;
}

void solve() {
	forn(i, input.size()) {
		point A = input[i].first;
		point B = input[i].second;
		
		vp curr_moves;

		if(is_valid(A) && is_valid(B) && A == B) {
			curr_moves.push_back(A);
		} else if(is_valid(A) && is_valid(B) && A != B && is_same_color(A, B)) {
			curr_moves.push_back(A);

			int delta_y = fabs(A.y - B.y);
			int delta_x = fabs(A.x - B.x);

			if(delta_x != 0 && eq((double)delta_y / delta_x, 1.0)) {
				// same diagonal
				curr_moves.push_back(B);
			} else {
				// two moves required
				point inter_move;

				int k = (B.x - A.x + B.y - A.y) / 2;
				if(A.x + k >= 7 ||  A.y + k >= 7 || A.x + k < 0 || A.y + k < 0) {
					k = (A.x - B.x + A.y - B.y) / 2;
					inter_move.x = B.x + k;
					inter_move.y = B.y + k;
				} else {
					inter_move.x = A.x + k;
					inter_move.y = A.y + k;
				}

				curr_moves.push_back(inter_move);
				curr_moves.push_back(B);
			}
		}
		sol.moves.push_back(curr_moves);
	}
}

string limited(const string &s) {
	return "=" + s + "=";
}

void write_solution() {
	mic cols_inverted;
	for(char c = 'A'; c <= 'H'; c++) {
		cols_inverted[c - 'A'] = c;
	}

	ifstream in;
	debug in.open("chess.ans");

	forn(i, sol.moves.size()) {
		char my_line[100];
		my_line[0] = '\0';

		if(sol.moves[i].size() == 0) {
			debug sprintf(my_line, "Impossible");
			cout << "Impossible" << endl;
		} else {
			cout << (sol.moves[i].size() - 1) << " ";
			debug sprintf(
				my_line + strlen(my_line), 
				"%ld ", 
				(sol.moves[i].size() - 1)
			);

			forn(j, sol.moves[i].size()) {
				cout << cols_inverted[(int)sol.moves[i][j].x] << " " << 
					((int)sol.moves[i][j].y + 1) << " ";

				debug sprintf(
					my_line + strlen(my_line), 
					"%c %d", 
					cols_inverted[(int)sol.moves[i][j].x], 
					((int)sol.moves[i][j].y + 1)
				);

				if(j != sol.moves[i].size() - 1) {
					sprintf(
						my_line + strlen(my_line), 
						" "
					); 
				}
			}

			cout << endl;
		}

		string ans_line;
		debug getline(in, ans_line);
		
		debug if(ans_line.compare(string(my_line)) != 0) {
			cout << limited(my_line) << " should be " << limited(ans_line) << " at line: " << i << endl;		
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

	run();

	return 0;
}