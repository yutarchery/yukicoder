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

vector<vector<ll>> my_calc(vector<vector<ll>> a, vector<vector<ll>> b) {
  vector<vector<ll>> ans;
  ans.resize(a.size());
  for (int i = 0; i < a.size(); i++) {
    ans[i].resize(b.size());
  }

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      for (int k = 0; k < a[0].size(); k++) {
        ans[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return ans;
}

vector<vector<ll>> a, b;

int main() {
  a.resize(2);
  for (int i = 0; i < 2; i++) {
    a[i].resize(2);
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
  }

  b.resize(2);
  for (int i = 0; i < 2; i++) {
    b[i].resize(2);
    for (int j = 0; j < 2; j++) {
      cin >> b[i][j];
    }
  }

  vector<vector<ll>> ans = my_calc(a, b);
  ans = my_calc(ans, ans);

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << (j == ans[i].size() - 1 ? '\n' : ' ');
    }
  }

  return 0;
}
