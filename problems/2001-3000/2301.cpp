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

int n, a[int(2e5 + 5)], b[int(2e5 + 5)];

set<Pii> graph[int(2e5 + 5)];
int rest[int(2e5 + 5)];
string ans[int(2e5 + 5)];

void solve(int idx) {
  int start = a[idx];
  queue<int> que;
  que.push(start);

  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (Pii next : graph[now]) {
      if (ans[next.second] != "") {
        continue;
      }

      if (now == a[next.second]) {
        ans[next.second] = "->";
      } else {
        ans[next.second] = "<-";
      }
      que.push(next.first);
      break;
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];

    rest[a[i]]++;
    rest[b[i]]++;

    graph[a[i]].insert({b[i], i});
    graph[b[i]].insert({a[i], i});
  }

  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (rest[i] == 1) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (Pii next : graph[q]) {
      int idx = next.second;

      if (a[idx] == q) {
        ans[idx] = "->";
      } else {
        ans[idx] = "<-";
      }

      rest[next.first]--;
      graph[next.first].erase({q, idx});
      if (rest[next.first] == 1) {
        que.push(next.first);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (ans[i].empty()) {
      solve(i);
    }

    cout << ans[i] << endl;
  }

  return 0;
}
