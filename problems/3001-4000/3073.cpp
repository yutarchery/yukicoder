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

bool compare(ll a, ll b, ll c, ll d) {
  if (a * d - b * c >= 0) {
    return true;
  } else {
    return false;
  }
}

ll my_gcd(ll a, ll b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return my_gcd(b, a % b);
  }
}

int n;
ll a[int(2e6 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  ll ans_a = a[1], ans_b = a[2];
  for (int i = 1; i + 1 <= n; i++) {
    if (!compare(ans_a, ans_b, a[i], a[i + 1])) {
      ans_a = a[i];
      ans_b = a[i + 1];
    }
  }
  ll g = my_gcd(ans_a, ans_b);
  cout << ans_a / g << " " << ans_b / g << endl;

  return 0;
}
