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

#define PUSH_OP 1
#define POP_OP 2

void read_data() {
	while(1) {
		bool is_s = true,
			is_q = true,
			is_pq = true;

		stack<short> s;
		queue<short> q;
		priority_queue<short> pq;

		int n;
		int scan_result = scanf("%d", &n);
		
		if(scan_result != 1) {
			break;
		}
		// cin >> n;

		forn(i, n) {
			int op,
			 	el;
			scanf("%d %d", &op, &el);
			// cin >> op >> el;

			if(op == PUSH_OP) {
				debug cout << "push " << el << endl;
				s.push(el);
				q.push(el);
				pq.push(el);
			} else if(op == POP_OP) {
				if(s.size() == 0) {
						is_s = false;
				} else {
					short s_val = s.top();

					if(s_val != el) {
						is_s = false;
					}
					s.pop();
				}

				if(q.size() == 0) {
					is_q = false;
				} else {
					short q_val = q.front();
					if(q_val != el) {
						is_q = false;
					}
					q.pop();
				}

				if(pq.size() == 0) {
					is_pq = false;
				} else {
					short pq_val = pq.top();
					if(pq_val != el) {
						is_pq = false;
					}
					pq.pop();
				}
			}
		}
		
		if(is_s && !is_q && !is_pq) {
			cout << "stack" << endl;
		} else if(!is_s && is_q && !is_pq) {
			cout << "queue" << endl;
		} else if(!is_s && !is_q && is_pq) {
			cout << "priority queue" << endl;
		} else if(is_s || is_q || is_pq) {
			cout << "not sure" << endl;
		} else {
			cout << "impossible" << endl;
		}
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