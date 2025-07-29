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

int n, a[10][4];
string r[10];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
    }
    cin >> r[i];
  }

  for (int k = 0; k <= 9; k++) {
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      if (r[i] == "YES") {
        flag = false;
        for (int j = 0; j < 4; j++) {
          if (a[i][j] == k) {
            flag = true;
          }
        }
      } else {
        for (int j = 0; j < 4; j++) {
          if (a[i][j] == k) {
            flag = false;
          }
        }
      }
      if (!flag) {
        break;
      }
    }

    if (flag) {
      cout << k << endl;
      break;
    }
  }

  return 0;
}
