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

ll n, a, b;
ll fac[int(2e5 + 5)];

int main() {
  cin >> n >> a >> b;

  fac[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % MOD2;
  }

  ll ans;
  if (a != b) {
    ans = fac[n] - fac[n - 1] * 2 + fac[n - 2];
    ans %= MOD2;
  } else {
    ans = fac[n] - fac[n - 1] * 2;
    ans %= MOD2;
  }

  if (ans < 0) {
    ans += MOD2;
  }
  cout << ans << endl;

  return 0;
}
