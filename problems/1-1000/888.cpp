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

ll n;
vector<Pll> p;

void prepare(ll num) {
  ll rest = num;
  for (ll i = 2; i * i <= num; i++) {
    if (rest % i != 0) {
      continue;
    }

    int cnt = 0;
    while (rest % i == 0) {
      rest /= i;
      cnt++;
    }

    p.push_back({i, cnt});
  }
  if (rest > 1) {
    p.push_back({rest, 1});
  }

  return;
}

int main() {
  cin >> n;
  prepare(n);

  ll ans = 1;
  for (int i = 0; i < p.size(); i++) {
    ll now = 1, sum = 1;
    for (int j = 0; j < p[i].second; j++) {
      now *= p[i].first;
      sum += now;
    }
    ans *= sum;
  }

  cout << ans << endl;

  return 0;
}
