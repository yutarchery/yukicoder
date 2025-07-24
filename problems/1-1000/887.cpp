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

ll n, now, n_max;
vector<ll> ans;

int main() {
  cin >> n;
  ans.push_back(n);
  now = n;
  n_max = n;

  while (now > 1) {
    if (now % 2 == 0) {
      now /= 2;
    } else {
      now = 3 * now + 1;
    }
    ans.push_back(now);
    n_max = max(now, n_max);
  }

  cout << ans.size() - 1 << endl;
  cout << n_max << endl;

  return 0;
}
