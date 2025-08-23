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

int h, w;
char c[405][405];
ll dp[405][405][2];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> c[i][j];
    }
  }

  dp[2][1][0] = 1;
  for (int i = 4; i <= h + w; i++) {
    for (int j = max(1, i - h); j <= min(i - 1, w); j++) {
      for (int k = max(1, i - h); k <= min(i - 1, w); k++) {
        if (j == k || c[i - j][j] != '.' || c[i - k][k] != '.') {
          continue;
        }

        dp[j][k][1] = (dp[j - 1][k - 1][0] + dp[j - 1][k][0] + dp[j][k - 1][0] +
                       dp[j][k][0]) %
                      MOD2;
      }
    }

    for (int j = max(1, i - h); j <= min(i - 1, w); j++) {
      for (int k = max(1, i - h); k <= min(i - 1, w); k++) {
        dp[j][k][0] = dp[j][k][1];
        dp[j][k][1] = 0;
      }
    }
  }
  cout << dp[w][w - 1][0] << endl;

  return 0;
}
