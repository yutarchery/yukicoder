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
ll a[int(2e5 + 5)], ans, cnt1, cnt2;

int main() {
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];

    if (a[i] == 1) {
      ans += 2 * (i - 1 - cnt2) + 3 * cnt2;
      cnt1++;
    } else if (a[i] == 2) {
      ans += (i - 1 - cnt1) + 3 * cnt1;
      cnt2++;
    } else {
      ans += (i - 1 - cnt1) + 2 * cnt1;
    }
  }
  cout << ans << endl;

  return 0;
}
