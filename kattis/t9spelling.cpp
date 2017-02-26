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
#define vs vector<string>

#define seb set<bool>
#define sei set<int>
#define seii set< pair<int, int> >
#define sell set<long long>

#define vvb vector< vector<bool> >
#define vvi vector< vector<int> >

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
	vs keys;
};

solution sol;

vs lines;

vs keypad;

void read_data() {
	keypad.push_back(" ");
	keypad.push_back("");
	keypad.push_back("abc");
	keypad.push_back("def");
	keypad.push_back("ghi");
	keypad.push_back("jkl");
	keypad.push_back("mno");
	keypad.push_back("pqrs");
	keypad.push_back("tuv");
	keypad.push_back("wxyz");

	int n;
	cin >> n;

	ignore;

	lines = vs(n);

	debug cout << lines.size() << endl;

	for(int i = 0; i < n; i++) {
		string line;
		getline(cin, line);
		debug cout << i << " " << line << endl;

		lines[i] = line;
	}

	ignore;
}

string get_code(char c) {
	forn(i, keypad.size()) {
		string::iterator itr = find(keypad[i].begin(), keypad[i].end(), c);
		if(itr != keypad[i].end()) {
			int pos = itr - keypad[i].begin();

			debug cout << pos << endl;

			string code = "";

			forn(j, pos + 1) {
				code += (char)(i + '0');
			}

			debug cout << "code for " << c << " is " << code << endl;

			return code;
		}
	}
}

void solve_line(int n) {
	string line = lines[n];
	string keys = "";

	for(int i = 0; i < line.length(); i++) {
		string code = get_code(line[i]);
			
		// pause
		if(keys.size() >= 1 && code[0] == keys[keys.size() - 1]) {
			keys += ' ';
		}

		keys += code;
	}

	sol.keys.push_back(keys);
}

void solve() {
    for(int i = 0; i < lines.size(); i++) {
    	solve_line(i);
    }
}

void write_solution() {
	forn(i, sol.keys.size()) {
		cout << "Case #" << (i + 1) << ": " << sol.keys[i] << endl;
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