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

int n, ans[int(1e4 + 5)];
bool visited[int(1e4 + 5)];

int main() {
  cin >> n;
  queue<int> que;
  que.push(1);
  ans[1] = 1;
  visited[1] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    int cnt = 0, rest = q;
    while (rest > 0) {
      cnt += rest % 2;
      rest /= 2;
    }

    for (int i = -1; i <= 1; i++) {
      int next = q + i * cnt;
      if (1 <= next && next <= n && !visited[next]) {
        visited[next] = true;
        ans[next] = ans[q] + 1;
        que.push(next);
      }
    }
  }

  cout << (visited[n] ? ans[n] : -1) << endl;

  return 0;
}
