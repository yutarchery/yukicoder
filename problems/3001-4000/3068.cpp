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

ll a, b, c, d, n, p, q, r, s, t;

int main() {
  cin >> a >> b >> c >> d >> n;
  cin >> p >> q >> r >> s >> t;

  for (ll i = 0; i <= a; i++) {
    for (ll j = 0; j <= b; j++) {
      ll x = t - (p * i + q * j), y = n - (i + j);
      if (x >= 0 && y >= 0) {
        if (r == s) {
          if (r * y == x && y <= c + d) {
            ll k = min(c, y);
            cout << i << " " << j << " " << k << " " << y - k << endl;
            return 0;
          }
        } else {
          if ((x - s * y) % (r - s) == 0) {
            ll k = (x - s * y) / (r - s);
            ll l = y - k;
            if (0 <= k && k <= c && 0 <= l && l <= d) {
              cout << i << " " << j << " " << k << " " << l << endl;
              return 0;
            }
          }
        }
      }
    }
  }

  return 0;
}
