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

ll w, h, n, s[105], k[105];

map<ll, bool> s_visited, k_visited;
ll s_cnt, k_cnt;

int main() {
  cin >> w;
  cin >> h;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> k[i];
    if (!s_visited[s[i]]) {
      s_visited[s[i]] = true;
      s_cnt++;
    }

    if (!k_visited[k[i]]) {
      k_visited[k[i]] = true;
      k_cnt++;
    }
  }

  ll ans = s_cnt * h + k_cnt * w - s_cnt * k_cnt - n;
  cout << ans << endl;

  return 0;
}
