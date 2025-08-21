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

ll a, b, c, d;
ll p, q, r, s, t;

priority_queue<Pll, vector<Pll>, greater<Pll>> que;
ll rest, ans;

int main() {
  cin >> a >> b >> c >> d;
  cin >> p >> q >> r >> s >> t;

  que.push({p, a});
  que.push({q, b});
  que.push({r, c});
  que.push({s, d});
  rest = t;

  while (!que.empty()) {
    Pll now = que.top();
    que.pop();

    if (rest >= now.first * now.second) {
      rest -= now.first * now.second;
      ans += now.second;
    } else {
      ans += rest / now.first;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
