/*You are given a weighted undirected graph. The vertices are enumerated from 1
to n. Your task is to find the shortest path between the vertex 1 and the vertex
n. Input

The first line contains two integers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), where n
is the number of vertices and m is the number of edges. Following m lines
contain one edge each in form ai, bi and wi (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106),
where ai, bi are edge endpoints and wi is the length of the edge.

It is possible that the graph has loops and multiple edges between pair of
vertices. Output

Write the only integer -1 in case of no path. Write the shortest path in
opposite case. If there are many solutions, print any of them. Examples Input
Copy

5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

Output
Copy

1 4 3 5

Input
Copy

5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

Output
Copy

1 4 3 5
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
int n, m, i, j, a, b, w, k, z;
ll d[100005], p[100005];
map<pair<ll, ll>, ll> mp;
priority_queue<ll> q;
vector<ll> v[100005];
void f(ll i) {
  if (i != 1)
    f(p[i]);
  cout << i << ' ';
}
int main() {
  cin >> n >> m;
  while (m--) {
    cin >> a >> b >> w;
    v[a].push_back(b);
    v[b].push_back(a);
    mp[{a, b}] = w;
    mp[{b, a}] = w;
  }

  for (i = 2; i <= n; i++)
    d[i] = 1e18;
  q.push(1);

  while (q.size()) {
    k = q.top();
    q.pop();
    for (i = 0; i < v[k].size(); i++) {
      z = v[k][i];
      w = mp[{k, z}];
      if (d[k] + w < d[z])
        d[z] = d[k] + w, p[z] = k, q.push(z);
    }
  }

  if (d[n] == 1e18)
    return cout << -1, 0;
  f(n);
  return 0;
}
