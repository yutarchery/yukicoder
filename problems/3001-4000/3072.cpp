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

int n, ka, kb, a[int(3e5 + 5)], b[int(3e5 + 5)];
int q, s[int(3e5 + 5)], t[int(3e5 + 5)], ans[int(3e5 + 5)];

priority_queue<Pii, vector<Pii>, greater<Pii>> que_a, que_b;
bool visited_a[int(3e5 + 5)], visited_b[int(3e5 + 5)];
int dist_a[int(3e5 + 5)], dist_b[int(3e5 + 5)], dist_ab;

void prepare_dist() {
  while (!que_a.empty()) {
    Pii q = que_a.top();
    que_a.pop();
    if (visited_a[q.second]) {
      continue;
    }
    visited_a[q.second] = true;
    dist_a[q.second] = q.first;

    for (int i = -1; i <= 1; i++) {
      int next = q.second + i;
      if (1 <= next && next <= n && !visited_a[next]) {
        que_a.push({q.first + 1, next});
      }
    }
  }

  while (!que_b.empty()) {
    Pii q = que_b.top();
    que_b.pop();
    if (visited_b[q.second]) {
      continue;
    }
    visited_b[q.second] = true;
    dist_b[q.second] = q.first;

    for (int i = -1; i <= 1; i++) {
      int next = q.second + i;
      if (1 <= next && next <= n && !visited_b[next]) {
        que_b.push({q.first + 1, next});
      }
    }
  }

  dist_ab = 1e9;
  int now_b = 1;
  for (int i = 1; i <= ka; i++) {
    for (int j = now_b; j <= kb; j++) {
      if (a[i] >= b[j]) {
        now_b = j;
      } else {
        break;
      }
    }

    dist_ab = min(dist_ab, abs(a[i] - b[now_b]));
    dist_ab = min(dist_ab, abs(a[i] - b[max(now_b - 1, 1)]));
    dist_ab = min(dist_ab, abs(a[i] - b[min(now_b + 1, kb)]));
  }

  return;
}

int main() {
  cin >> n >> ka >> kb;
  for (int i = 1; i <= ka; i++) {
    cin >> a[i];
    que_a.push({0, a[i]});
  }
  for (int i = 1; i <= kb; i++) {
    cin >> b[i];
    que_b.push({0, b[i]});
  }
  prepare_dist();

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> s[i] >> t[i];

    ans[i] = abs(s[i] - t[i]);
    ans[i] = min(ans[i], dist_a[s[i]] + dist_a[t[i]]);
    ans[i] = min(ans[i], dist_a[s[i]] + dist_ab + dist_b[t[i]]);
    ans[i] = min(ans[i], dist_b[s[i]] + dist_b[t[i]]);
    ans[i] = min(ans[i], dist_b[s[i]] + dist_ab + dist_a[t[i]]);
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
