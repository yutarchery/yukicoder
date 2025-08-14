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

ll my_pow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

int n;
ll p, q, a[205], v[205][4];
ll cnt[205][int(1e5 + 5)];
const ll vals[4] = {10, 9, 7, 5};

int main() {
  cin >> n >> p >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      v[i][j] = my_pow(vals[j], a[i], p);
    }
  }

  for (int k = n; k >= 1; k--) {
    for (int l = k + 1; l <= n; l++) {
      cnt[k][(v[k][2] + v[l][3]) % p]++;
    }

    for (int i = 0; i < p; i++) {
      cnt[k][i] += cnt[k + 1][i];
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ll now = (v[i][0] + v[j][1]) % p;
      ll rest = (p + q - now) % p;

      ans += cnt[j + 1][rest];
    }
  }
  cout << ans << endl;

  return 0;
}
