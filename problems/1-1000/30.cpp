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

int n, m, p[1505], r[1505];
ll q[1505];

vector<Pli> graph[105];
ll ans[105];

int main() {
  cin >> n;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> p[i] >> q[i] >> r[i];
    graph[r[i]].push_back({q[i], p[i]});
  }
  ans[n] = 1;

  queue<int> que;
  que.push(n);
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    if (ans[q] == 0) {
      continue;
    }

    bool flag = false;
    for (Pli next : graph[q]) {
      ans[next.second] += ans[q] * next.first;
      que.push(next.second);
      flag = true;
    }

    if (flag) {
      ans[q] = 0;
    }
  }

  for (int i = 1; i <= n - 1; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
