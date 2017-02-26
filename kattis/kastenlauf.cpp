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

template<typename U, typename V>
ostream& operator<<(ostream &os, const map<U, V> &m) {
    for(auto kv : m) {
        cout << kv.first << " --> " << kv.second << endl;
    }

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
	
};

solution sol;

int dd(ii x, ii y) {
	return fabs(x.first - y.first) + 
		fabs(x.second - y.second);
}

struct union_find {
	vi elements;

	union_find(int n) {
		elements = vi(n);

		forn(i, elements.size()) {
			elements[i] = i;
		}
	}

	void unite(int x, int y) {
		elements[find(x)] = find(y);
	}

	int find(int x) {
		if(x == elements[x]) {
			return x;
		} else {
			return find(elements[x]);
		}
	}

	void print() {
		forn(i, elements.size()) {
			cout << i << " -> " << find(i) << endl; 
		}
	}
};

#define MAX_DIST 1000
#define DEBUG 0

void read_data() {
	int t;
	cin >> t;
	forn(i, t) {
		int n;
		cin >> n;

		vii coords(n + 2);
		forn(j, n + 2) {
			cin >> coords[j].first >> coords[j].second;
		}

		// O(n^2) graph check
		// can be improved by sorting probably
		union_find uf(coords.size());
		forn(j, coords.size()) {
			forn(k, coords.size()) {
				if(j != k && dd(coords[j], coords[k]) <= MAX_DIST) {
					uf.unite(j, k);
				}
			}
		}

		debug uf.print();

		bool is_happy = ( uf.find(0) == uf.find(coords.size() - 1) );

		cout << (is_happy ? "happy" : "sad") << endl;
	}
}

void solve() {
    
}

void write_solution() {
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