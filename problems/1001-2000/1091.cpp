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
  vector<ll> node;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1);
  }

  void insert(int idx, ll val) {
    idx += n - 1;
    node[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[2 * idx + 1] ^ node[2 * idx + 2];
    }
    return;
  }

  ll solve(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    if (r <= a || b <= l) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }
    return solve(a, b, 2 * k + 1, l, (l + r) / 2) ^
           solve(a, b, 2 * k + 2, (l + r) / 2, r);
  }
};

int n, q, l[int(2e5 + 5)], r[int(2e5 + 5)];
ll a[int(2e5 + 5)];

int main() {
  cin >> n >> q;
  SegmentTree tree(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tree.insert(i, a[i]);
  }

  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 1; i <= q; i++) {
    cout << tree.solve(l[i], r[i] + 1) << endl;
  }

  return 0;
}
