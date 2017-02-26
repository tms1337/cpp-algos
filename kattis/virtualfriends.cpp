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
ostream& operator<<(ostream &os, const map<U, V> &m) {
	for(auto kv : m) {
		cout << kv.first << " --> " << kv.second << endl;
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

struct node {
	int parent;
	int sum;

	node() {

	}

	node(int parent, int sum) {
		this->parent = parent;
		this->sum = sum;
	}

	bool operator==(const node &n) {
		return 
			this->parent == n.parent;
	}

	bool operator!=(const node &n) {
		return !(*this == n);
	}
};

msi name_inds;
vector<node> union_find;

node find(int x) {
	if(union_find[x].parent == x) {
		return union_find[x];
	} else {
		return find(union_find[x].parent);
	}
}

void reset() {
	union_find.clear();
	name_inds.clear();
}

int unify(int x, int y) {
	node find_x = find(x);
	node find_y = find(y);

	if(find_x != find_y) {
		union_find[find_x.parent].parent = find_y.parent;
		union_find[find_y.parent].sum += find_x.sum + 1;
	}

	return union_find[find_y.parent].sum;
}

ostream& operator<<(ostream &os, const node &n) {
    os << "(" << n.parent << ", " << n.sum << ")";

    return os;
}

void print_uf() {
	for(int i = 0; i < union_find.size(); i++) {
		cout << union_find[i] << " ";
		cout << endl;
	}
}

#define DEBUG 0

void read_data() {
	int n;
	cin >> n;

	forn(i, n) {
		reset();
		int next = 0;

		int F;
		cin >> F;

		forn(j, F) {
			debug cout << "Iteration " << j << endl;
			debug cout << name_inds << endl;
			debug print_uf();
			debug cout << endl;

			string a, b;
			cin >> a >> b;

			if(name_inds.find(a) == name_inds.end()) {
				name_inds[a] = next;
				union_find.push_back(node(next, 0));
				next++;
			}

			if(name_inds.find(b) == name_inds.end()) {
				name_inds[b] = next;
				union_find.push_back(node(next, 0));
				next++;
			}

			cout << unify(name_inds[a], name_inds[b]) + 1 << endl;
		}

		debug cout << "End " << endl;
		debug cout << name_inds << endl;
		debug print_uf();
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