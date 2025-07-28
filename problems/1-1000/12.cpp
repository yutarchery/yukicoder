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

int n, a[10];
bool dig[10], visited[int(5e6 + 5)], is_prime[int(5e6 + 5)];
vector<vector<int>> oks;
int cnt[int(5e6 + 5)][10];

void prepare() {
  for (int i = 2; i <= int(5e6); i++) {
    if (visited[i]) {
      continue;
    }
    is_prime[i] = true;
    for (int j = i; j <= int(5e6); j += i) {
      visited[j] = true;
    }
  }

  vector<int> tmp;
  tmp.push_back(1);
  for (int i = 2; i <= int(5e6); i++) {
    if (!is_prime[i]) {
      continue;
    }

    bool flag = true;
    int rest = i;
    while (rest > 0) {
      if (!dig[rest % 10]) {
        flag = false;
      }
      cnt[i][rest % 10]++;
      rest /= 10;
    }

    if (flag) {
      tmp.push_back(i);
    } else {
      tmp.push_back(i - 1);
      if (!tmp.empty()) {
        oks.push_back(tmp);
      }
      tmp.resize(0);
      tmp.push_back(i + 1);
    }
  }
  tmp.push_back(int(5e6));
  if (!tmp.empty()) {
    oks.push_back(tmp);
  }

  for (int i = 2; i <= int(5e6); i++) {
    for (int j = 0; j < 10; j++) {
      cnt[i][j] += cnt[i - 1][j];
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dig[a[i]] = true;
  }

  prepare();
  int ans = -1;
  for (vector<int> v : oks) {
    bool flag = true;
    int l = v[0], r = v[v.size() - 1];

    for (int j = 0; j <= 9; j++) {
      if (dig[j]) {
        if (cnt[r][j] - cnt[l - 1][j] >= 1) {
          continue;
        } else {
          flag = false;
        }
      } else {
        if (cnt[r][j] - cnt[l - 1][j] == 0) {
          continue;
        } else {
          flag = false;
        }
      }
    }

    if (flag) {
      ans = max(ans, r - l);
    }
  }
  cout << ans << endl;

  return 0;
}
