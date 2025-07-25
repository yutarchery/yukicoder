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

int k, n;
bool is_prime[int(2e5 + 5)], visited_prime[int(2e5 + 5)];
vector<int> primes;
int my_hash[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

void prepare() {
  for (int i = 2; i <= n; i++) {
    if (visited_prime[i]) {
      continue;
    }
    visited_prime[i] = true;
    is_prime[i] = true;
    for (int j = i; j <= n; j += i) {
      visited_prime[j] = true;
    }
  }
  for (int i = k; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  return;
}

int calc_hash(int num) {
  if (visited[num]) {
    return my_hash[num];
  }

  visited[num] = true;
  if (num <= 9) {
    return my_hash[num] = num;
  }

  int ans = 0, rest = num;
  while (rest > 0) {
    ans += rest % 10;
    rest /= 10;
  }

  return my_hash[num] = calc_hash(ans);
}

int main() {
  cin >> k;
  cin >> n;

  prepare();
  int ans_c = 0, ans_p = 0;
  for (int i = 0; i < primes.size(); i++) {
    int cnt = 0;
    bool now_visited[10] = {};
    for (int j = 0; i + j < primes.size(); j++) {
      int h = calc_hash(primes[i + j]);
      if (now_visited[h]) {
        break;
      } else {
        now_visited[h] = true;
        cnt++;
      }
    }
    if (ans_c <= cnt) {
      ans_c = cnt;
      ans_p = primes[i];
    }
  }
  cout << ans_p << endl;

  return 0;
}
