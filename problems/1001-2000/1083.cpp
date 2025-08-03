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

int n;
ll k, a[25];

ll solve(int idx) {
  ll rest = k;
  for (int i = 1; i <= n - 1; i++) {
    if (idx % 2 == 1) {
      rest %= a[i];
    }
    idx /= 2;
  }
  return rest % a[n];
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<ll>());

  ll ans = 0;
  for (int i = 0; i < (1 << (n - 1)); i++) {
    ans = max(ans, solve(i));
  }
  cout << ans << endl;

  return 0;
}
