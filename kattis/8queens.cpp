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
#define vvi vector< vector<int> >
#define vi vector<int>
#define vd vector<double>
#define ii pair<int, int>
#define mii map<int, int>
#define mid map<int, double>
#define stll stack<long long>
#define vb vector<bool>
#define vvb vector< vector<bool> >
#define sb set<bool>
#define si set<int>
#define sell set<long long>
#define seii set< pair<int, int> >

#define loop(karna, n) for(int karna = 0; karna < n; karna++)

#define DEBUG 0
#define debug if(DEBUG)

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

string input_file = "/home/faruk/Desktop/secret/generated099";
string output_file = input_file + ".ans";

#define ROW_CNT 8
#define COL_CNT 8

struct solution {
	bool is_valid;
};

solution sol;

vvb board(8, vb(8));
seii q_pos;

void read_data() {
	output_file = input_file + ".ans";

	input_file += ".in";
	ifstream in;


	for(int i = 0; i < ROW_CNT; i++) {
		for(int j = 0; j < COL_CNT; j++) {
			char c;

			debug in >> c;
			else cin >> c;

			board[i][j] = (c == '*');

			if(c == '*') {
				q_pos.insert(make_pair(i, j));
			}
		}
	}

	sol.is_valid = true;
}

void check_rows() {
	if(!sol.is_valid) {
		return;
	}

	for(int i = 0; i < ROW_CNT; i++) {
		if(count(board[i].begin(), board[i].end(), true) >= 2) {
			debug cout << "Row: " << i << endl;
			sol.is_valid = false;
			break;
		}
	}
}

void check_cols() {
	if(!sol.is_valid) {
		return;
	}

	for(int j = 0; j < COL_CNT; j++) {
		int q_cnt = 0;
		for(int i = 0; i < ROW_CNT; i++) {
			if(board[i][j]) {
				q_cnt++;
			}
		}

		if(q_cnt >= 2) {
			debug cout << "Col: " << j << endl;
			sol.is_valid = false;
			break;
		}
	}
}

void check_diags() {
	if(!sol.is_valid) {
		return;
	}

	for(seii::iterator i = q_pos.begin(); i != q_pos.end(); i++) {
		for(seii::iterator j = q_pos.begin(); j != q_pos.end(); j++) {
			if(i != j) {
				int delta_y = fabs(i->second - j->second);
				int delta_x = fabs(i->first- j->first);

				if(eq((double)delta_y / delta_x, 1.0)) {
					debug cout << "Diag: " << *i << " " << *j << endl;
					sol.is_valid = false;
					goto loop_out;
				}
			}
		}
	} 

	loop_out:
	return;
}

void solve() {
	if(q_pos.size() != 8) {
		sol.is_valid = false;
		return;
	}

	check_rows();
	check_cols();
	check_diags();
}

void write_solution() {
	if(sol.is_valid) {
		cout << "valid";
	} else {
		cout << "invalid";		
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