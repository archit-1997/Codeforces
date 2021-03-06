/**
 * @author      : Archit
 * @cf-handle 	: archit1997
 * @GitHub 		: archit-1997
 * @email 		: architsingh456@gmail.com
 * @Contest		: Codeforces Round 675 Div 2
 * @Problem     : Bargain
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define ld long double
#define line cout << "-------------" << endl;
#define F first
#define S second
#define P pair<ll, ll>
#define V vector<ll>
#define VP vector<pair<ll, ll>>
#define VS vector<string>
#define VV vector<vector<ll>>
#define pb push_back
#define pf push_front
#define PQ priority_queue<ll>
#define PQ_G priority_queue<ll, vector<ll>, greater<ll>>
#define mod 1000000007
#define inf 1e18

#define ps(x, y) fixed << setprecision(y) << x
#define w(tt)                                                                  \
  ll tt;                                                                       \
  cin >> tt;                                                                   \
  while (tt--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define ma(arr, n, type) type *arr = new type[n]
#define pbds                                                                   \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>

void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

int main() {

  init();

  string s;
  cin >> s;
  ll n = s.size();
  // we are traversing from right to left (reason for reverse loop)
  // sz is the number of elements that we have covered
  // pre stores the (number of ways by which we can remove the right
  // part)*(resulting place value) mul stores the place value of the current
  // number ans stores the answer

  ll pre = 0, sz = 0, mul = 1, ans = 0;
  for (ll i = n - 1; i >= 0; i--) {
    ll num = s[i] - '0';
    sz++;
    // left calculation
    ll lways = (i * (i + 1)) / 2;
    lways %= mod;
    ll t1 = (lways * mul) % mod;
    t1 = (t1 * num) % mod;
    ans = (ans + t1) % mod;

    // right calculation
    ll t2 = (pre * num) % mod;
    ans = (ans + t2) % mod;
    pre += (sz * mul);
    pre %= mod;
    mul = (mul * 10) % mod;
  }

  cout << ans;

  return 0;
}
