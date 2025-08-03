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

string t;
int d;
ll dp[int(1e5 + 5)][10];

int main() {
  cin >> t;
  cin >> d;

  dp[0][0] = 1;
  for (int i = 1; i <= t.length(); i++) {
    if (t[i - 1] == '?') {
      for (int j = 0; j <= 9; j++) {
        for (int k = 0; k <= 9; k++) {
          int next = j + k;
          if (next >= 10) {
            next -= 9;
          }
          dp[i][next] += dp[i - 1][j];
          dp[i][next] %= MOD;
        }
      }
    } else {
      for (int j = 0; j <= 9; j++) {
        int next = j + (t[i - 1] - '0');
        if (next >= 10) {
          next -= 9;
        }
        dp[i][next] += dp[i - 1][j];
        dp[i][next] %= MOD;
      }
    }
  }
  cout << dp[t.length()][d] << endl;

  return 0;
}
