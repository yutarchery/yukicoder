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

int n, k, num[10];
int sum[10], cnt[10], ans = 0;

void solve(int idx = 1, int sz = 0) {
  if (idx == n + 1) {
    if (sz == k) {
      int now_min = 1e9, now_max = 0;
      for (int i = 1; i <= k; i++) {
        int now = sum[i];
        for (int j = 1; j <= 9; j++) {
          if (j != cnt[i]) {
            now *= j;
          }
        }

        now_min = min(now_min, now);
        now_max = max(now_max, now);
      }

      int p = 1;
      for (int i = 1; i <= 9; i++) {
        p *= i;
      }

      if ((now_max - now_min) % p == 0) {
        ans = max(ans, (now_max - now_min) / p);
      } else {
        ans = max(ans, (now_max - now_min) / p + 1);
      }
      return;
    } else {
      return;
    }
  }

  for (int i = 1; i <= min(sz + 1, k); i++) {
    sum[i] += num[idx];
    cnt[i]++;
    solve(idx + 1, max(sz, i));
    cnt[i]--;
    sum[i] -= num[idx];
  }

  return;
}

int main() {
  cin >> n;
  cin >> k;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }

  solve();
  cout << ans << endl;

  return 0;
}
