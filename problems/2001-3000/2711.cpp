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

ll n, m, k, dp[int(2e4 + 5)][32];

int pop_count(int a, int b) {
  int ans = 0;
  while (a > 0 || b > 0) {
    if (a % 2 == 1 && b % 2 == 1) {
      ans++;
    }
    a /= 2;
    b /= 2;
  }
  return ans;
}

int main() {
  cin >> n >> m >> k;
  for (int j = 0; j < (1 << n); j++) {
    dp[1][j] = 1;
  }

  for (int i = 2; i <= m; i++) {
    for (int j = 0; j < (1 << n); j++) {
      for (int l = 0; l < (1 << n); l++) {
        if (pop_count(j, l) >= k) {
          dp[i][j] += dp[i - 1][l];
          dp[i][j] %= MOD2;
        }
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j < (1 << n); j++) {
    ans += dp[m][j];
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
