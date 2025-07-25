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

int n, w[105], sum = 0;
bool visited[105][int(1e4 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    sum += w[i];
  }

  if (sum % 2 != 0) {
    cout << "impossible" << endl;
    return 0;
  }

  visited[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= int(1e4); j++) {
      if (visited[i - 1][j]) {
        visited[i][j] = true;
        visited[i][j + w[i]] = true;
      }
    }
  }

  cout << (visited[n][sum / 2] ? "possible" : "impossible") << endl;

  return 0;
}
