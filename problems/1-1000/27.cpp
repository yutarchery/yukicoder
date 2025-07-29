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

int v[4], ans = 1e9;
bool visited[35][35][35][4][100];

void solve(int i, int j, int k, int idx = 0, int cnt = 0) {
  if (idx == 4) {
    ans = min(ans, cnt);
    return;
  }

  if (visited[i][j][k][idx][cnt]) {
    return;
  }
  visited[i][j][k][idx][cnt] = true;

  for (int ii = 0; i * ii <= v[idx]; ii++) {
    for (int jj = 0; i * ii + j * jj <= v[idx]; jj++) {
      for (int kk = 0; i * ii + j * jj + k * kk <= v[idx]; kk++) {
        if (i * ii + j * jj + k * kk == v[idx]) {
          solve(i, j, k, idx + 1, cnt + ii + jj + kk);
        }
      }
    }
  }

  return;
}

int main() {
  for (int i = 0; i < 4; i++) {
    cin >> v[i];
  }

  for (int i = 1; i <= 30; i++) {
    for (int j = i; j <= 30; j++) {
      for (int k = j; k <= 30; k++) {
        solve(i, j, k);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
