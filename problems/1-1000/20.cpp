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

int n, v, ox, oy, l[205][205];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
bool visited[205][205][1005][2];

int main() {
  cin >> n >> v >> ox >> oy;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> l[i][j];
    }
  }

  queue<array<int, 4>> que;
  que.push({1, 1, v, 0});
  visited[1][1][v][0] = true;

  while (!que.empty()) {
    array<int, 4> q = que.front();
    que.pop();
    int i = q[0], j = q[1], val = q[2], cnt = q[3];

    if (i == oy && j == ox && cnt == 0) {
      visited[i][j][val * 2][1] = true;
      que.push({i, j, val * 2, 1});
    }

    for (int k = 0; k < 4; k++) {
      int next_i = i + di[k], next_j = j + dj[k],
          next_val = val - l[next_i][next_j];

      if (1 <= next_i && next_i <= n && 1 <= next_j && next_j <= n &&
          1 <= next_val && !visited[next_i][next_j][next_val][cnt]) {
        que.push({next_i, next_j, next_val, cnt});
        visited[next_i][next_j][next_val][cnt] = true;
      }
    }
  }

  for (int i = 1; i <= 1000; i++) {
    for (int j = 0; j <= 1; j++) {
      if (visited[n][n][i][j]) {
        YES();
        return 0;
      }
    }
  }
  NO();

  return 0;
}
