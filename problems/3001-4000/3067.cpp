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

int n, rest, t[int(2e5 + 5)], k, x[int(2e5 + 5)];
int ans = 0, x_idx = 1, x_cnt = 0;

int main() {
  cin >> n >> rest;
  for (int i = 2; i <= n; i++) {
    cin >> t[i];
  }
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> x[i];
  }

  for (int i = 2; i <= n; i++) {
    while (rest <= t[i]) {
      if (x_cnt == 0) {
        cout << -1 << endl;
        return 0;
      }
      rest += 10;
      ans++;
      x_cnt--;
    }

    rest -= t[i];

    for (int j = x_idx; j <= k; j++) {
      if (x[j] <= i) {
        x_cnt++;
        x_idx++;
      } else {
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
