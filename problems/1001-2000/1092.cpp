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

ll p, n, a[int(1e5 + 5)];
char s[int(1e5 + 5)];

int main() {
  cin >> p >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    cin >> s[i];
  }

  ll ans = a[1];
  for (int i = 2; i <= n; i++) {
    if (s[i] == '+') {
      ans += a[i];
    } else if (s[i] == '-') {
      ans -= a[i];
    } else if (s[i] == '*') {
      ans *= a[i];
    } else {
      ans *= my_pow(a[i], p - 2, p);
    }

    ans %= p;
    if (ans < 0) {
      ans += p;
    }
  }
  cout << ans << endl;

  return 0;
}
