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

Mat calc(Mat a, Mat b, ll mod) {
  Mat ans = {{0, 0}, {0, 0}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        ans[i][j] += (a[i][k] * b[k][j]) % mod;
        ans[i][j] %= mod;
      }
    }
  }

  return ans;
}

Mat my_pow(Mat a, ll n, ll mod) {
  if (n == 0) {
    return {{1, 0}, {0, 1}};
  } else if (n % 2 == 0) {
    Mat m = calc(a, a, mod);
    return my_pow(m, n / 2, mod);
  } else {
    Mat m = my_pow(a, n - 1, mod);
    return calc(m, a, mod);
  }
}

int main() {
  ll a, b, n;
  cin >> a >> b >> n;

  if (n == 0) {
    cout << 0 << endl;
    return 0;
  } else if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  Mat m = my_pow({{a, b}, {1, 0}}, n - 1, MOD);
  cout << m[0][0] << endl;

  return 0;
}
