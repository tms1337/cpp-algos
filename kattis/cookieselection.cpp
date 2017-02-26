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
	
};

solution sol;

struct median_queue {
	priority_queue<int> left;
	priority_queue<int> right;
	int med;

	median_queue() {
		med = -1;
	}

	int size() {
		return left.size() + (med == -1 ? 0 : 1) + right.size();
	}

	void push(int el) {
		if(size() == 0) {
			left.push(el);
		} else if(size() == 1) {
			if(el > left.top()) {
				right.push(-el);
			} else {
				right.push(-left.top());
				left.pop();
				left.push(el);
			}
		} else if(size() == 2) {
			if(el < left.top()) {
				med = left.top();
				left.pop();
				left.push(el);
			} else if(el < -right.top()) {
				med = el;
			} else {
				med = -right.top();
				right.pop();

				right.push(-el);
			}
		} else if(size() > 2) {
			if(left.size() == right.size()) {
				if(el < med) {
					left.push(el);
				} else {
					right.push(-el);
					left.push(med);

					med = -right.top();
					right.pop();
				}
			} else {
				if(el < med) {
					left.push(el);
					left.push(med);

					right.push(-left.top());
					left.pop();

					med = left.top();
					left.pop();
				} else {
					right.push(-el);
				}
			}
		}
	}

	int pop() {
		if(size() == 1) {
			int val = left.top();
			left.pop();

			return val;
		} else if(size() == 2) {
			int val = -right.top();
			right.pop();

			return val;
		} else if(size() == 3) {
			int val = med;
			med = -1;
			return val;
		} else {
			int val = med;
			if(left.size() == right.size()) {
				med = -right.top();
				right.pop();
			} else {
				med = left.top();
				left.pop();
			}

			return val;
		}
	}

	void print() {
		cout << "Left" << endl;
		auto left_cpy = left;
		while(left_cpy.size() != 0) {
			cout << left_cpy.top() << " ";
			left_cpy.pop();
		}
		cout << endl;

		cout << "Median " << med << endl;

		cout << "Right" << endl;
		auto right_cpy = right;
		while(right_cpy.size() != 0) {
			cout << right_cpy.top() << " ";
			right_cpy.pop();
		}
		cout << endl;

	}
};

#define DEBUG 0

void read_data() {
	median_queue m;

	while(1) {
		char c[100];
		int scan_result = scanf("%s", c);

		if(scan_result != 1) {
			break;
		}

		if(c[0] == '#') {
			// m.pop();
			cout << m.pop() << endl;
		} else {
			m.push(stoi(c));
		}

		debug m.print();
		debug cout << endl << endl;
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