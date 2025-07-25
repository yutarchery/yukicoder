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

int n, c, v, s[1505], t[1505], y[1505], m[1505];

vector<array<int, 3>> graph[55];
ll dp[55][305];
bool visited[55][305];

int main() {
  cin >> n;
  cin >> c;
  cin >> v;
  for (int i = 1; i <= v; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= v; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= v; i++) {
    cin >> y[i];
  }
  for (int i = 1; i <= v; i++) {
    cin >> m[i];
  }

  for (int i = 1; i <= v; i++) {
    graph[s[i]].push_back({t[i], y[i], m[i]});
  }
  priority_queue<Pii, vector<Pii>, greater<Pii>> que;
  que.push({0, 1});

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= c; j++) {
      dp[i][j] = 1e16;
    }
  }
  dp[1][0] = 0;

  while (!que.empty()) {
    Pii q = que.top();
    que.pop();
    int i = q.second, j = q.first;
    if (visited[i][j]) {
      continue;
    }
    visited[i][j] = true;
    for (array<int, 3> a : graph[i]) {
      int next = a[0], cost = a[1];
      if (j + cost > c) {
        continue;
      }
      if (visited[next][j + cost]) {
        continue;
      }

      dp[next][j + cost] = min(dp[next][j + cost], dp[i][j] + a[2]);
      que.push({j + cost, next});
    }
  }

  ll ans = 1e16;
  for (int j = 0; j <= c; j++) {
    if (visited[n][j]) {
      ans = min(ans, dp[n][j]);
    }
  }
  cout << (ans == 1e16 ? -1 : ans) << endl;

  return 0;
}
