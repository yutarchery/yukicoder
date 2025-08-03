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

int n, k, q;
ll a[int(1e5 + 5)], x[int(1e5 + 5)];
ll sum[int(1e5 + 5)];
vector<ll> vals;

int solve(ll num) {
  if (num < vals[0]) {
    return 0;
  }

  int ok = 0, ng = vals.size();
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (vals[mid] <= num) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return ok + 1;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i];
  }

  for (int i = 1; i + k - 1 <= n; i++) {
    vals.push_back(sum[i + k - 1] - sum[i - 1]);
  }
  sort(vals.begin(), vals.end());

  for (int i = 1; i <= q; i++) {
    cout << solve(x[i]) << endl;
  }

  return 0;
}
