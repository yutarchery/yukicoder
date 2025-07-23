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

string a, b;

int main() {
  cin >> a >> b;

  if (a == "0" || b == "0") {
    if (a == b) {
      cout << "E" << endl;
    } else {
      cout << "S" << endl;
    }

    return 0;
  }

  if (a == "1" || b == "1") {
    cout << "S" << endl;
    return 0;
  }
  if (a == "2" && b == "2") {
    cout << "E" << endl;
    return 0;
  }
  cout << "P" << endl;

  return 0;
}
