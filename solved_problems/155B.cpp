/*Ilya plays a card game by the following rules.

A player has several cards. Each card contains two non-negative integers
inscribed, one at the top of the card and one at the bottom. At the beginning of
the round the player chooses one of his cards to play it. If the top of the card
contains number ai, and the bottom contains number bi, then when the player is
playing the card, he gets ai points and also gets the opportunity to play
additional bi cards. After the playing the card is discarded.

More formally: let's say that there is a counter of the cards that can be
played. At the beginning of the round the counter equals one. When a card is
played, the counter decreases by one for the played card and increases by the
number bi, which is written at the bottom of the card. Then the played card is
discarded. If after that the counter is not equal to zero, the player gets the
opportunity to play another card from the remaining cards. The round ends when
the counter reaches zero or the player runs out of cards.

Of course, Ilya wants to get as many points as possible. Can you determine the
maximum number of points he can score provided that you know his cards? Input

The first line contains a single integer n (1 ≤ n ≤ 1000) — the number of cards
Ilya has.

Each of the next n lines contains two non-negative space-separated integers — ai
and bi (0 ≤ ai, bi ≤ 104) — the numbers, written at the top and the bottom of
the i-th card correspondingly. Output

Print the single number — the maximum number of points you can score in one
round by the described rules. Examples Input Copy

2
1 0
2 0

Output
Copy

2

Input
Copy

3
1 0
2 0
0 2

Output
Copy

3

Note

In the first sample none of two cards brings extra moves, so you should play the
one that will bring more points.

In the second sample you should first play the third card that doesn't bring any
points but lets you play both remaining cards.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int compare(const vector<ll> &v1, const vector<ll> &v2) {
  if (v1[1] != v2[1])
    return v1[1] > v2[1];
  else
    return v1[0] > v2[0];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  vector<vector<ll>> v(n, vector<ll>(2));

  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    v[i][0] = a;
    v[i][1] = b;
  }

  sort(v.begin(), v.end(), compare);

  // for(ll i=0;i<n;i++)
  //    cout<<v[i][0]<<" "<<v[i][1]<<endl;

  ll sum = 0, c = 1, i = 0;

  while (1) {
    if (c == 0 || i == n)
      break;
    sum += v[i][0];
    c--;
    c += v[i][1];
    i++;
  }

  cout << sum << endl;

  return 0;
}
