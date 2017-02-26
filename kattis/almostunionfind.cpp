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

template<typename T>
ostream& operator<<(ostream &os, const set<T> &s) {
	cout << "{";
	for(auto &el : s) {
		cout << el + 1 << ", ";
	}
	cout << "}";

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

struct node {
	int id;
	int parent;
	ll cnt;
	ll sum;
	set<int> children;
};

struct union_find {
	vector<node> elements;

    union_find(int n) {
    	elements = vector<node>(n);

        forn(i, elements.size()) {
        	elements[i].id = i;
        	elements[i].parent = i;
        	elements[i].cnt = 1;
        	elements[i].sum = i + 1;
        }
    }

    void unite(int x, int y) {
    	int find_x = find(x);
    	int find_y = find(y);

    	if(find_x != find_y) {
			elements[find_x].parent = find_y;
			elements[find_y].children.insert(find_x);  	
			elements[find_y].cnt += elements[find_x].cnt;  	
			elements[find_y].sum += elements[find_x].sum;  	
    	}
    }

    void move(int x, int y) {
    	int find_x = find(x);
    	int find_y = find(y);

    	if(find_x == find_y) {
    		return;
    	}

    	if(elements[x].children.size() > 0) {
    		if(elements[x].parent == x) {
    			// at top
    			int first_child = *(elements[x].children.begin());
    			elements[first_child].parent = first_child;
    			elements[first_child].cnt = 1;
    			elements[first_child].sum = first_child + 1;

    			for(auto child : elements[x].children) {
    				if(child != first_child) {
    					elements[child].parent = first_child;
    					elements[first_child].children.insert(child);
    					elements[first_child].cnt += elements[child].cnt;
    					elements[first_child].sum += elements[child].sum;
    				}
    			}
    		} else {
    			// not at top
    			auto parent = elements[x].parent;
    			for(auto child : elements[x].children) {
    				elements[child].parent = parent;
    				elements[parent].children.insert(child);
    			}
    		}
    	}
		
		if(elements[x].parent != x) {
			elements[elements[x].parent].children.erase(x);
			
			if(find_x != elements[x].parent) {
				elements[elements[x].parent].cnt--;
				elements[elements[x].parent].sum -= (x + 1);
			}

			elements[find_x].cnt--;
			elements[find_x].sum -= (x + 1);
		}		
		
		elements[x].children.clear();

		elements[x].parent = find_y;
		elements[x].cnt = 1;
		elements[x].sum = x + 1;
		elements[find_y].children.insert(x);
		elements[find_y].cnt++;
		elements[find_y].sum += (x + 1);
    }

    int find(int x) {
        if(elements[x].parent == x) {
        	return x;
        } else {
        	return find(elements[x].parent);
        }
    }

    void get_cnt_sum(ll &cnt, ll &sum, int x) {
    	cnt++;
    	sum += x + 1;
    	for(auto child : elements[x].children) {
    		get_cnt_sum(cnt, sum, child);
    	}
    }

    pair<ll, ll> val(int x) {
    	int find_x = find(x);

    	return make_pair(elements[find_x].cnt, elements[find_x].sum);
    }

    pair<ll, ll> get_real_val(int x) {
    	int find_x = find(x);

    	ll cnt = 0, sum = 0;
    	get_cnt_sum(cnt, sum, find_x);
		
		return make_pair(cnt, sum);
    }

    void print_node(int i, int lvl = 0) {
    	cout << string(lvl, '\t') << "( " << elements[i].id + 1 << " p: " <<
			elements[i].parent + 1 << " c: " << elements[i].cnt << 
			" s: " << elements[i].sum << " { ";

		for(auto child : elements[i].children) {
			cout << child + 1 << ", ";
		}
		cout << "} )" << endl;

		for(auto child : elements[i].children) {
			print_node(child, lvl + 1);
		}
    }

    void print() {
    	forn(i, elements.size()) {
    		if(elements[i].parent == i) {
				print_node(i);
    		}
    	}
    }

    bool check_el(int x) {
    	auto real_val = get_real_val(x);

		return elements[x].cnt == real_val.first &&
			elements[x].sum == real_val.second;
    }

    bool check() {
    	forn(i, elements.size()) {
    		if(!check_el(i)) {
    			cout << "Mismatch at: " << i << endl;
    			return false;
    		}
    	}

    	return true;
    }
};

#define DEBUG 1

void read_data() {
	int t = 0;

	while(1) {
		int n, m;

		int scan_result = scanf("%d %d", &n, &m);

		if(scan_result != 2) {
			break;
		}

		union_find uf(n);

		forn(i, m) {
			int op;
			scanf("%d", &op);

			int p, q;

			if(op == 1) {
				scanf("%d %d", &p, &q);
				debug cout << "union " << p << " " << q << endl;
				uf.unite(p - 1, q - 1);
			} else if(op == 2) {
				scanf("%d %d", &p, &q);
				debug cout << "move " << p << " to " << q << endl;
				uf.move(p - 1, q - 1);
			} else if(op == 3) {
				scanf("%d", &p);
				debug cout << "count for " << p << ": ";
				pair<ll, ll> val = uf.val(p - 1);
				cout << val.first << " " << val.second << endl;
			}

			debug uf.check();
			debug uf.print();
			debug cout << endl;
		}

		++t;
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