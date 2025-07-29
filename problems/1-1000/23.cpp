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

int h, a, d;
double ans[int(1e4 + 5)];
bool visited[int(1e4 + 5)];

double solve(int num) {
  if (visited[num]) {
    return ans[num];
  }
  visited[num] = true;
  if (num == 0) {
    return ans[num] = 0;
  }

  double res = solve(max(0, num - a)) + 1;
  res = min(res, solve(max(0, num - d)) + 1.5);
  return ans[num] = res;
}

int main() {
  cin >> h >> a >> d;
  cout << fixed << setprecision(10) << solve(h) << endl;

  return 0;
}
