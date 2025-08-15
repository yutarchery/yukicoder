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

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1);
  }

  void insert(int idx, int val) {
    idx += n - 1;
    node[idx] += val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[2 * idx + 1] + node[2 * idx + 2];
    }
    return;
  }

  int get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }

    return get_sum(a, b, 2 * k + 1, l, (l + r) / 2) +
           get_sum(a, b, 2 * k + 2, (l + r) / 2, r);
  }
};

int n, q, a[int(1e5 + 5)], x[int(1e5 + 5)], y[int(1e5 + 5)];

vector<int> vals;
map<int, bool> visited;
map<int, int> idx;

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!visited[a[i]]) {
      visited[a[i]] = true;
      vals.push_back(a[i]);
    }
  }

  sort(vals.begin(), vals.end());
  for (int i = 0; i < vals.size(); i++) {
    idx[vals[i]] = i;
  }

  SegmentTree tree(n + 5);
  for (int i = 1; i <= n; i++) {
    tree.insert(idx[a[i]], 1);
  }

  for (int i = 1; i <= q; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= q; i++) {
    if (a[x[i]] <= a[y[i]]) {
      cout << 0 << endl;
      continue;
    }

    cout << tree.get_sum(idx[a[y[i]]] + 1, idx[a[x[i]]]) << endl;
  }

  return 0;
}
