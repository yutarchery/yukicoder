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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)];
vector<int> graph[int(4e5 + 5)];

int ans[int(4e5 + 5)];

void solve(int start, int cnt) {
  queue<int> que;
  que.push(start);
  ans[start] = cnt;

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (ans[next] == 0) {
        ans[next] = cnt;
        que.push(next);
      }
    }
  }

  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];

    graph[a[i]].push_back(b[i] + n);
    graph[a[i] + n].push_back(b[i]);

    graph[b[i]].push_back(a[i] + n);
    graph[b[i] + n].push_back(a[i]);
  }

  int cnt = 1;
  for (int i = 1; i <= 2 * n; i++) {
    if (ans[i] == 0) {
      solve(i, cnt);
      cnt++;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (ans[i] != ans[i + n]) {
      No();
      return 0;
    }
  }
  Yes();

  return 0;
}
