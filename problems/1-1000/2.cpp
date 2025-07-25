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

ll n;
vector<ll> primes;
map<ll, bool> is_win[2], visited[2];

void prepare(ll num) {
  ll rest = num;
  for (ll i = 2; i * i <= num; i++) {
    if (rest % i == 0) {
      primes.push_back(i);
      while (rest % i == 0) {
        rest /= i;
      }
    }
  }

  if (rest > 1) {
    primes.push_back(rest);
  }
  return;
}

bool solve(int turn, ll rest) {
  if (visited[turn][rest]) {
    return is_win[turn][rest];
  }

  visited[turn][rest] = true;
  if (rest == 1) {
    if (turn == 0) {
      return is_win[turn][rest] = false;
    } else {
      return is_win[turn][rest] = true;
    }
  }

  if (turn == 0) {
    bool flag = false;
    for (ll p : primes) {
      ll now = rest;
      while (now % p == 0) {
        now /= p;
        flag = flag | solve(1, now);
      }
    }
    return is_win[turn][rest] = flag;
  } else {
    bool flag = true;
    for (ll p : primes) {
      ll now = rest;
      while (now % p == 0) {
        now /= p;
        flag = flag & solve(0, now);
      }
    }
    return is_win[turn][rest] = flag;
  }
}

int main() {
  cin >> n;
  prepare(n);
  cout << (solve(0, n) ? "Alice" : "Bob") << endl;

  return 0;
}
