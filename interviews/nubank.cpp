/* You are given an array of n non-negative integers. You are asked q times to
 * find how many of those n integers belongs to a [l,r] range of non-negative
 * integers. Each query may have a diferente range.
 */
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;

ll j[100001], l[100001], r[100001];

int main () {
	int n, q;
	set<int> s;

	// input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> j[i];
		s.insert(j[i]); // building distinct elements set
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l[i];
		s.insert(l[i]); // building distinct elements set
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> r[i];
		s.insert(r[i]); // building distinct elements set
	}

	// input compress
	map<int, int> m;
	int a = 1;
	for (int x : s) {
		m[x] = a++;
	}
	// updating input values
	vector<int> h(m.size()+2, 0); // initting histogram
	for (int i = 0; i < n; i++) {
		j[i] = m[j[i]];
		h[j[i]]++; // building histogram
	}
	for (int i = 0; i < q; i++) {
		l[i] = m[l[i]];
		r[i] = m[r[i]];
	}

	// prefix sum on histogram
	vector<int> p(h.size()+2, h[1]);
	for (size_t i = 1; i <= h.size(); i++) {
		p[i] = h[i+1] + p[i - 1];
	}

	// answering queries
	for (int i = 0; i < q; i++) {
		if (l[i] == 1)
			cout << p[r[i]-1] << endl;
		else
			cout << p[r[i]-1] - p[l[i]-2] << endl;
	}

	return 0;
}
