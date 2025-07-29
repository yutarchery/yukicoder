#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

ull my_gcd(ull a, ull b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  }
  return my_gcd(b, a % b);
}

ull n, m;

int main() {
  cin >> n >> m;
  ull g = my_gcd(n, m);
  ull gn = n / g, gm = m / g;

  while (gm % 10 == 0) {
    gm /= 10;
  }
  while (gm % 2 == 0) {
    gm /= 2;
    if (gn % 2 == 0) {
      gn /= 2;
    } else {
      gn = (((gn % 10) * 10) / 2) % 10;
    }
  }
  while (gm % 5 == 0) {
    gm /= 5;

    if (gn % 5 == 0) {
      gn /= 5;
    } else {
      gn = (((gn % 10) * 10) / 5) % 10;
    }
  }

  if (gm > 1) {
    cout << -1 << endl;
  } else {
    while (gn % 10 == 0) {
      gn /= 10;
    }
    while (gn >= 10) {
      gn %= 10;
    }

    cout << gn << endl;
  }

  return 0;
}
