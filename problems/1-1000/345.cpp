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
vector<int> c, w;

int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'c') {
      c.push_back(i);
    } else if (s[i] == 'w') {
      w.push_back(i);
    }
  }

  if (c.size() < 1 || w.size() < 2) {
    cout << -1 << endl;
    return 0;
  }

  int w_idx = 0, ans = 1e9;
  for (int i = 0; i < c.size(); i++) {
    if (c[i] > w[w.size() - 2]) {
      break;
    }

    for (int j = w_idx; j <= w.size() - 2; j++) {
      if (c[i] < w[j]) {
        w_idx = j;
        break;
      }
    }

    ans = min(ans, w[w_idx + 1] - c[i] + 1);
  }
  cout << (ans == 1e9 ? -1 : ans) << endl;

  return 0;
}
