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

int h, w, cnt[15][15][21];
char a[15][15];

const int di[2] = {1, 0}, dj[2] = {0, 1};

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  cnt[1][1][1] = 1;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      for (int k = 0; k < 2; k++) {
        int next_i = i + di[k], next_j = j + dj[k];
        if (next_i <= h && next_j <= w) {
          if (a[next_i][next_j] == 'o') {
            for (int l = 0; l <= h + w; l++) {
              cnt[next_i][next_j][l + 1] += cnt[i][j][l];
            }
          }
          if (a[next_i][next_j] == 'x') {
            for (int l = 1; l <= h + w; l++) {
              cnt[next_i][next_j][l - 1] += cnt[i][j][l];
            }
          }
        }
      }
    }
  }

  int ans = 0;
  for (int l = 0; l <= h + w; l++) {
    ans += cnt[h][w][l];
  }
  cout << ans << endl;

  return 0;
}
