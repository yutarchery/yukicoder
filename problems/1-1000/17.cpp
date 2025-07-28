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

int n, m, a[int(1e4 + 5)], b[int(1e4 + 5)];
ll s[55], c[int(1e4 + 5)];

ll dist[55][55];

int main() {
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= n - 1; j++) {
      if (i != j) {
        dist[i][j] = 1e16;
      }
    }
  }

  for (int i = 0; i <= n - 1; i++) {
    cin >> s[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    dist[a[i]][b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  ll ans = 1e16;
  for (int i = 1; i <= n - 2; i++) {
    for (int j = 1; j <= n - 2; j++) {
      if (i == j) {
        continue;
      }

      ans = min(ans, dist[0][i] + dist[i][j] + dist[j][n - 1] + s[0] + s[i] +
                         s[j] + s[n - 1]);
    }
  }
  cout << ans << endl;

  return 0;
}
