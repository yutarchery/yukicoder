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

int n, k, a[int(1e5 + 5)];
vector<int> ans;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int eq = 0, over = 2e9;
  while (over - eq > 1) {
    int mid = (eq + over) / 2;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= mid) {
        cnt++;
      }
    }

    if (cnt > k) {
      over = mid;
    } else {
      eq = mid;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (a[i - 1] <= eq && eq < a[i]) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  if (ans.size() > 0) {
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) {
      cout << " " << ans[i];
    }
  }
  cout << endl;

  return 0;
}
