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

#define DEBUG 0

void read_data() {
	int T;
	cin >> T;

	forn(i, T) {
		string dmy;
		getline(cin, dmy);

		int N;
		cin >> N;

		vi cumm(N);
		map< int, vi > locations;
 		forn(j, N) {
			int curr;
			cin >> curr;
			
			if(j == 0) {
				cumm[j] = curr;
			} else {
				cumm[j] = cumm[j - 1] + curr;
			}

			locations[ cumm[j] ].push_back(j);
		}

		debug cout << cumm << endl;
		debug cout << locations << endl;

		int cnt = 0;
		forn(j, N) {
			int val = (j > 0) ? cumm[j - 1] : 0;
			auto curr_locations = locations[47 + val];

			debug cout << "Checking " << 47 + val << endl;

			debug cout << "\t" << curr_locations << " | " << j << endl;

			if(curr_locations.size() > 0) {
				debug cout << "Enter" << endl;

				forn(k, curr_locations.size()) {
					if(curr_locations[k] > j - 1) {
						debug cout << curr_locations << " @ " << k << " " << val << endl;
						cnt++;
					}
				}
			}
		}

		cout << cnt << endl; 
		debug cout << endl;
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