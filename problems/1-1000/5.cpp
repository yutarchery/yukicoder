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

int l, n, w[int(1e4 + 5)], sum[int(1e4 + 5)];

int main() {
  cin >> l;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  sort(w + 1, w + n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + w[i];
    if (l < sum[i]) {
      cout << i - 1 << endl;
      return 0;
    }
  }
  cout << n << endl;

  return 0;
}
