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

int ans = 0;
bool sosu, heiho, rippo, kanzen;

void check_sosu(int n) {
  if (n <= 1) {
    return;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return;
    }
  }
  ans++;
  sosu = true;
  return;
}

void check_heiho(int n) {
  if (n <= 1) {
    return;
  }
  for (int i = 2; i * i <= n; i++) {
    if (i * i == n) {
      ans++;
      heiho = true;
      return;
    }
  }
  return;
}

void check_rippo(int n) {
  if (n <= 1) {
    return;
  }
  for (int i = 2; i * i * i <= n; i++) {
    if (i * i * i == n) {
      ans++;
      rippo = true;
      return;
    }
  }
  return;
}

void check_kanzen(int n) {
  if (n <= 0) {
    return;
  }

  int sum = 0;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      sum += i;
    } else if (n % i == 0) {
      sum += i;
      sum += n / i;
    }
  }

  if (sum == n * 2) {
    ans++;
    kanzen = true;
  }
  return;
}

int main() {
  int n;
  cin >> n;

  check_sosu(n);
  check_heiho(n);
  check_rippo(n);
  check_kanzen(n);

  if (ans == 1) {
    if (sosu) {
      cout << "Sosu!" << endl;
    } else if (heiho) {
      cout << "Heihosu!" << endl;
    } else if (rippo) {
      cout << "Ripposu!" << endl;
    } else {
      cout << "Kanzensu!" << endl;
    }
  } else {
    cout << n << endl;
  }

  return 0;
}
