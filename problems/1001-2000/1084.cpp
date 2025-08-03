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
ll a[int(1e5 + 5)];

ll pows[int(1e5 + 5)], cnt[int(1e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  int r = 1;
  ll now = a[1];
  for (int i = 1; i <= n; i++) {
    for (int j = r + 1; j <= n; j++) {
      if (now * a[j] >= ll(1e9)) {
        break;
      } else {
        r = j;
        now *= a[j];
      }
    }

    pows[i] += r - i + 1;
    cnt[i]++;
    cnt[r + 1]--;
    now /= a[i];
    r = max(r, i + 1);
    if (r == i + 1) {
      now = a[i + 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    pows[i] += pows[i - 1] - cnt[i - 1];
  }
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= my_pow(a[i], pows[i], MOD);
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
