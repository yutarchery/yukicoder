#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

struct SegmentTree {
private:
  int n;
  vector<int> node;
  const int MAX = 1e9;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1, MAX);
  }

  void insert(int idx, int val) {
    idx += n - 1;
    node[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = min(node[2 * idx + 1], node[2 * idx + 2]);
    }
    return;
  }

  int get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (b <= l || r <= a) {
      return MAX;
    }
    if (a <= l && r <= b) {
      return node[k];
    }
    return min(get_min(a, b, 2 * k + 1, l, (l + r) / 2),
               get_min(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, q, a[int(1e5 + 5)], op, l, r, loc[int(1e5 + 5)];

int main() {
  cin >> n >> q;
  SegmentTree tree(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    loc[a[i]] = i;
    tree.insert(i, a[i]);
  }

  while (q--) {
    cin >> op >> l >> r;
    if (op == 1) {
      tree.insert(l, a[r]);
      tree.insert(r, a[l]);
      swap(loc[a[l]], loc[a[r]]);
      swap(a[l], a[r]);
    } else {
      int m = tree.get_min(l, r + 1);
      cout << loc[m] << endl;
    }
  }

  return 0;
}
