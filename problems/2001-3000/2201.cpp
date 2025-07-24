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

string s;
int ans = 0;

void solve(int idx = 0, bool alp = false, bool num = false, bool code = false) {
  if (idx == s.length()) {
    if (alp && num && code) {
      ans++;
    }
    return;
  }

  solve(idx + 1, true, num, code);
  if (s[idx] == 'l' || s[idx] == 'o') {
    solve(idx + 1, alp, true, code);
  }
  if (s[idx] == 'a' || s[idx] == 's') {
    solve(idx + 1, alp, num, true);
  }

  return;
}

int main() {
  cin >> s;
  solve();
  cout << ans << endl;

  return 0;
}
