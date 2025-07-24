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

int n, q, a[int(5e5 + 5)], l[int(5e5 + 5)], r[int(5e5 + 5)];
int cnt[int(5e5 + 5)];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];
    cnt[l[i]]++;
    cnt[r[i] + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
    cout << (a[i] + cnt[i]) % 2 << (i == n ? '\n' : ' ');
  }

  return 0;
}
