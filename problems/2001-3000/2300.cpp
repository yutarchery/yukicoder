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

ll n, a[int(2e5 + 5)];
bool bits[int(2e5 + 5)][30];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    ll rest = a[i];
    for (int j = 0; j < 30; j++) {
      bits[i][j] = rest % 2;
      rest /= 2;
    }
  }

  ll ans = 0;
  for (int j = 0; j < 30; j++) {
    ll p = (1ll << j), rest = n * (n + 1) / 2;

    bool now = true;
    int l;
    for (int i = 1; i <= n; i++) {
      if (now && !bits[i][j]) {
        l = i;
        now = false;
      } else if (bits[i][j]) {
        now = true;
      }
      if (!bits[i][j]) {
        rest -= i - l + 1;
      }
    }

    ans += p * rest;
  }

  cout << ans << endl;

  return 0;
}
