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

vector<int> arr;

bool in_order = true;
bool in_order_reversed = true;

void read_data() {
	int n;
	scanf("%d", &n);

	arr = vi(n);

	forn(i, n) {
		scanf("%d", &arr[i]);

		if(i > 0 && arr[i] < arr[i - 1]) {
			in_order = false;
		}

		if(i > 0 && arr[i] > arr[i - 1]) {
			in_order_reversed = false;
		}
	}
}

struct node {
	int ind;
	int val;

	node *left;
	node *right;

	int left_cnt;
	int right_cnt;
	int my_val;

	node(int ind = 0, int val = 0) {
		this->ind = ind;
		this->val = val;

		left = nullptr;
		right = nullptr;

		left_cnt = 0;
		right_cnt = 0;
		my_val = 1;
	}

	node(const node &n) {
		this->ind = n.ind;
		this->val = n.val;

		this->left = nullptr;
		this->right = nullptr;

		left_cnt = 0;
		right_cnt = 0;
		my_val = 1;
	}
};

struct binary_tree {
	node *root;

	binary_tree() {
		root = nullptr;
	} 

	void insert_recursively(node n, node **curr) {
		while(1) {
			if((*curr) == nullptr) {
				(*curr) = new node(n);
				break;
			} else {
				if(n.ind > (*curr)->ind) {
					(*curr)->right_cnt++;
					curr = &((*curr)->right);
				} else {
					(*curr)->left_cnt++;
					curr = &((*curr)->left);				
				}
			}
		}
		
	}

	void insert(int ind, int val) {
		insert_recursively(node(ind, val), &root);
	}

	int width_left() {
		int width = 0;
		node *curr = root;
		
		while(curr != nullptr) {
			width++;
			curr = curr->left;
		}

		return width;
	}

	void lvl_cnt(int &cnt, int depth = 0, node *curr = (node*)(-1)) {
		if(curr == (node*)(-1)) {
			curr = root;
			cnt = 0;
		}

		if(curr != nullptr) {
			if(depth > cnt) {
				cnt = depth;
			}

			lvl_cnt(cnt, depth + 1, curr->left);	
			lvl_cnt(cnt, depth + 1, curr->right);	
		}
	}

	int size(node *curr = (node*)(-1)) {
		if(curr == (node*)(-1)) {
			curr = root;
		}

		if(curr	== nullptr) {
			return 0;
		} else {
			return 1 + size(curr->left) + size(curr->right);
		}
	}

	void print_lvl(int lvl, int space_cnt, int depth = 0, node *curr = (node*)(-1)) {
		if(curr == (node*)(-1)) {
			curr = root;
		}

		if(curr == nullptr) {
			cout << "(x x x)" << string(space_cnt, ' ');
			return;
		}

		if(lvl == depth) {
			cout << "(" << curr->val << " " << curr->left_cnt << " " << 
				curr->right_cnt << " " << curr->my_val << ")" << string(space_cnt, ' ');
		} else {
			print_lvl(lvl, space_cnt, depth + 1, curr->left);
			print_lvl(lvl, space_cnt, depth + 1, curr->right);
		}
	}

	#define LEFT -1
	#define RIGHT 1

	void get(int &total, int ind, int dir) {
		node *curr = root;
		total = 0;

		while(1) {
			if(curr->ind != ind) {
				if(dir == LEFT) {
					if(ind > curr->ind) {
						total += curr->my_val;
						total += curr->left_cnt;
						curr->right_cnt--;

						curr = curr->right;
					} else {
						curr->left_cnt--;

						curr = curr->left;
					}
				} else if(dir == RIGHT) {
					if(ind < curr->ind) {
						total += curr->my_val;
						total += curr->right_cnt;
						curr->left_cnt--;

						curr = curr->left;
					} else {
						curr->right_cnt--;

						curr = curr->right;
					}
				}
			} else {
				curr->my_val = 0;
				if(dir == LEFT) {
					total += curr->left_cnt;
				} else if(dir == RIGHT) {
					total += curr->right_cnt;
				}
				break;
			}
		}
	}

	void print(int lvl = 0, node *curr = (node*)(-1)) {
		int width = width_left();
		int lvls;

	 	lvl_cnt(lvls);

		forn(i, lvls + 1) {
			cout << string(9 * (width - 1 - i), ' ');
			print_lvl(i, width - 1 - i);
			cout << endl;
		}
	}
};

binary_tree tree;

void create_tree(const vector<int> &arr, int from, int to) {
	if(to - from == 1) {
		tree.insert(from, arr[from]);
	} else if(to - from >= 2) {
		int middle = from + (to - from) / 2;

		tree.insert(middle, arr[middle]);

		create_tree(arr, from, middle);
		create_tree(arr, middle + 1, to);
	}
}

void solve() {
    create_tree(arr, 0, arr.size());
	
	map<int, int> places;
	forn(i, arr.size()) {
		places[arr[i]] = i;
	}

	debug tree.print();

    int for_right = arr.size(), for_left = 1;

	int total;
    forn(used_up,  arr.size()) {
    	if(used_up % 2 == 0) {
    		tree.get(total, places[for_left], LEFT);
    		for_left++;
    		printf("%d\n", total);
    	} else {
    		tree.get(total, places[for_right], RIGHT);
    		for_right--;
    		printf("%d\n", total);
    	}
    }
}

void write_solution() {

}

void run() {
    read_data();
    if(in_order) {
    	forn(i, arr.size()) {
    		printf("%d\n", 0);
    	}
    } else if(in_order_reversed) {
    	forn(i, arr.size()) {
    		printf("%d\n", arr.size() - 1 - i);
    	}
    } else {
	    solve();
	    write_solution();
    }
}

int main(int argc, char **argv) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

	run();

	return 0;
}