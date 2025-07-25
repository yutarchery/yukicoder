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

int n;
vector<int> primes;
bool visited[int(1e4 + 5)];

void prepare() {
  for (int i = 2; i <= n; i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    primes.push_back(i);
    for (int j = i; j <= n; j += i) {
      visited[j] = true;
    }
  }

  return;
}

bool is_win[int(1e4 + 5)][2], solved[int(1e4 + 5)][2];

bool solve(int num, int turn) {
  if (solved[num][turn]) {
    return is_win[num][turn];
  }
  solved[num][turn] = true;

  if (num <= 1) {
    return is_win[num][turn] = true;
  }

  bool flag = false;
  for (int i = 0; i < primes.size(); i++) {
    if (num < primes[i]) {
      break;
    }
    if (!solve(num - primes[i], 1 - turn)) {
      flag = true;
    }
  }

  return is_win[num][turn] = flag;
}

int main() {
  cin >> n;
  prepare();
  cout << (solve(n, 0) ? "Win" : "Lose") << endl;

  return 0;
}
