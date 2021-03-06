/*After you had helped George and Alex to move in the dorm, they went to help
their friend Fedor play a new computer game «Call of Soldiers 3».

The game has (m + 1) players and n types of soldiers in total. Players «Call of
Soldiers 3» are numbered form 1 to (m + 1). Types of soldiers are numbered from
0 to n - 1. Each player has an army. Army of the i-th player can be described by
non-negative integer xi. Consider binary representation of xi: if the j-th bit
of number xi equal to one, then the army of the i-th player has soldiers of the
j-th type.

Fedor is the (m + 1)-th player of the game. He assume that two players can
become friends if their armies differ in at most k types of soldiers (in other
words, binary representations of the corresponding numbers differ in at most k
bits). Help Fedor and count how many players can become his friends. Input

The first line contains three integers n, m, k (1 ≤ k ≤ n ≤ 20; 1 ≤ m ≤ 1000).

The i-th of the next (m + 1) lines contains a single integer xi
(1 ≤ xi ≤ 2n - 1), that describes the i-th player's army. We remind you that
Fedor is the (m + 1)-th player. Output

Print a single integer — the number of Fedor's potential friends.
Examples
Input
Copy

7 3 1
8
5
111
17

Output
Copy

0

Input
Copy

3 3 3
1
2
3
4

Output
Copy

3*/

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int cnt_ones(int val) {
  // Using Brian Kernighan’s Algorithm.
  // This method of counting no. of ones in binary representation
  // can be found here below:
  // http://www.geeksforgeeks.org/count-set-bits-in-an-integer/

  int ret = 0;
  while (val > 0) {
    ret++;
    val = val & (val - 1);
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); // Used for fast IO
  cin >> n >> m >> k;
  vector<int> v(m);
  int i, val, ans = 0;
  for (i = 0; i < m; i++)
    cin >> v[i];
  cin >> val;
  for (i = 0; i < m; i++)
    if (cnt_ones(val ^ v[i]) <= k)
      ans++;
  cout << ans << "\n";
  return 0;
}
