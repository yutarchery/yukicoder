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

Mat mat_calc(Mat a, Mat b, ll mod) {
  Mat ans = {{0, 0}, {0, 0}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        ans[i][j] += a[i][k] * b[k][j] % mod;
        ans[i][j] %= mod;

        if (ans[i][j] < 0) {
          ans[i][j] += mod;
        }
      }
    }
  }

  return ans;
}

Mat mat_pow(Mat a, ll n, ll mod) {
  if (n == 0) {
    return {{1, 0}, {0, 1}};
  } else if (n % 2 == 0) {
    return mat_pow(mat_calc(a, a, mod), n / 2, mod);
  } else {
    return mat_calc(a, mat_pow(a, n - 1, mod), mod);
  }
}

ll a, b, c, d, s, t, n, k;

int main() {
  cin >> a >> b;
  cin >> c >> d;
  cin >> s >> t;
  cin >> n >> k;

  Mat p = mat_pow({{a, b}, {c, d}}, n, k);
  ll r = (p[0][0] * s + p[0][1] * t) % k;
  if (r < 0) {
    r += k;
  }
  ll u = (p[1][0] * s + p[1][1] * t) % k;
  if (u < 0) {
    u += k;
  }
  cout << r << " " << u << endl;

  return 0;
}
