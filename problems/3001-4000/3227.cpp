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

ll mod;
int n, q;
Mat a = {{0, 0}, {0, 0}}, ans[int(1e5 + 5)];

Mat my_calc(Mat a, Mat b, ll mod) {
  Mat ans = {{0, 0}, {0, 0}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        ans[i][j] += a[i][k] * b[k][j];
        ans[i][j] %= mod;

        if (ans[i][j] < 0) {
          ans[i][j] += mod;
        }
      }
    }
  }
  return ans;
}

struct SegmentTree {
private:
  int n;
  vector<Mat> node;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1, {{0, 0}, {0, 0}});
  }

  void insert(int idx, Mat m, ll mod) {
    idx += n - 1;
    node[idx] = m;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = my_calc(node[2 * idx + 1], node[2 * idx + 2], mod);
    }
    return;
  }

  Mat solve(int a, int b, ll mod, int idx = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (b <= l || r <= a) {
      return {{1, 0}, {0, 1}};
    }
    if (a <= l && r <= b) {
      return node[idx];
    }
    return my_calc(solve(a, b, mod, 2 * idx + 1, l, (l + r) / 2),
                   solve(a, b, mod, 2 * idx + 2, (l + r) / 2, r), mod);
  }
};

int main() {
  cin >> mod >> n;
  SegmentTree tree(n + 5);

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        cin >> a[j][k];
      }
    }
    tree.insert(i, a, mod);
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    int idx, l, r;
    cin >> idx >> l >> r;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        cin >> a[j][k];
      }
    }
    tree.insert(idx, a, mod);
    ans[i] = tree.solve(l, r + 1, mod);
  }

  for (int i = 1; i <= q; i++) {
    for (int j = 0; j < 2; j++) {
      cout << ans[i][j][0] << " " << ans[i][j][1] << endl;
    }
  }

  return 0;
}
