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

vector<vector<ll>> calc(int sz, vector<vector<ll>> a, vector<vector<ll>> b) {
  vector<vector<ll>> ans;
  for (int i = 0; i < sz; i++) {
    vector<ll> v;
    v.resize(sz);
    ans.push_back(v);
  }

  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      for (int k = 0; k < sz; k++) {
        ans[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return ans;
}

int main() {
  vector<vector<ll>> a;
  for (int i = 0; i < 2; i++) {
    a.push_back({0, 0});
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<ll>> tmp = calc(2, a, a);
  vector<vector<ll>> ans = calc(2, tmp, a);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << ans[i][j] << (j == 1 ? '\n' : ' ');
    }
  }

  return 0;
}
