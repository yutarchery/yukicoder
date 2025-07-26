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

int n;
ll a[1505], b[1505], ans = 1e16;

ll solve(int start) {
  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  for (int i = 1; i <= n; i++) {
    que.push({a[i], 0});
  }

  for (int i = start; i <= n; i++) {
    Pli q = que.top();
    que.pop();
    q.first += b[i] / 2;
    q.second++;
    que.push(q);
  }
  for (int i = 1; i <= start - 1; i++) {
    Pli q = que.top();
    que.pop();
    q.first += b[i] / 2;
    q.second++;
    que.push(q);
  }

  int res = 0;
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    res = max(res, q.second);
  }

  return res;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; i++) {
    ans = min(ans, solve(i));
  }
  cout << ans << endl;

  return 0;
}
