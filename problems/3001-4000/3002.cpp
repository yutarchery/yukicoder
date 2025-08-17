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

int a, b;
ll ans[int(1e4 + 5)];

int main() {
  cin >> a >> b;
  ans[b] = a;

  for (int i = b; i >= 2; i--) {
    ll now = ans[i];
    ans[i] = 0;
    ans[i - 1] += -1 * now;
    ans[i - 2] += -1 * now;
  }

  cout << ans[1] << " " << ans[0] << endl;

  return 0;
}
