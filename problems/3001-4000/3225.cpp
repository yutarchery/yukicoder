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

const ll p = 67;
bool visited[67][67][67][67];

void solve(int a, int b, int c, int d) {
  for (int i = 1; i <= p; i++) {
    visited[(a * i) % p][(b * i) % p][(c * i) % p][(d * i) % p] = true;
  }

  return;
}

Mat mat_resize(int a, int b) {
  Mat ans;
  ans.resize(a);
  for (int i = 0; i < a; i++) {
    ans[i].resize(b);
  }
  return ans;
}

Mat mat_calc(Mat a, Mat b) {
  Mat ans = mat_resize(a.size(), b.size());
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      for (int k = 0; k < a[0].size(); k++) {
        ans[i][j] += a[i][k] * b[j][k];
        ans[i][j] %= 67;
      }
    }
  }
  return ans;
}

int main() {
  Mat a = mat_resize(2, 2), b = mat_resize(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i < p; i++) {
    for (int ii = 0; ii < p; ii++) {
      for (int j = 0; j < p; j++) {
        for (int jj = 0; jj < p; jj++) {
          if (i * jj - ii * j == 0) {
            continue;
          }
          if (visited[i][ii][j][jj]) {
            continue;
          }

          Mat now = {{i, ii}, {j, jj}};
          if (mat_calc(now, a) == mat_calc(b, now)) {
            Yes();
            return 0;
          }
          solve(i, ii, j, jj);
        }
      }
    }
  }

  No();

  return 0;
}
