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

struct solution {
	bool is_ok;
};

solution sol;

#define DIGIT_CNT 10

struct node {
	int cnt;
	vector<node*> children;

	node() {
		cnt = 0;

		children = 
			vector<node*>(10, nullptr);
	}
};

#define DEBUG 0

struct phonebook {
	node* root;
	
	bool insert(string phone) {
		node* curr_node = root;
		
		int was_null = false;

		for(int i = 0; i < phone.length(); i++) {
			char c = phone[i];

			int digit = c - '0';
			if(curr_node->children[digit] == nullptr) {
				was_null = true;
				curr_node->children[digit] = new node;
				curr_node->cnt++;
				curr_node = curr_node->children[digit];
			} else {
				curr_node = curr_node->children[digit];
			}
		}

		return was_null;
	}
};

vs phones;

void read_data() {
	int n;
	cin >> n;

	phones = vs(n);
	forn(i, n) {
		cin >> phones[i];
	}
}

void solve() {
	sol.is_ok = true;

	phonebook p;
	p.root = new node;

	sort(phones.begin(), phones.end(), [](string a, string b) {
		return a > b;
	});
	
	debug cout << phones << endl;

    for(auto phone : phones) {
    	if(!p.insert(phone)) {
    		sol.is_ok = false;
    		break;
    	}
    }
}

void write_solution() {
	cout << (sol.is_ok ? "YES" : "NO") << endl;
}

void run() {
    read_data();
    solve();
    write_solution();
}

int main(int argc, char **argv) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t; 
	cin >> t;

	forn(i, t) {
		run();
	}

	return 0;
}