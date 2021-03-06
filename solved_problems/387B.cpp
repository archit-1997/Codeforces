/*George decided to prepare a Codesecrof round, so he has prepared m problems
for the round. Let's number the problems with integers 1 through m. George
estimates the i-th problem's complexity by integer bi.

To make the round good, he needs to put at least n problems there. Besides, he
needs to have at least one problem with complexity exactly a1, at least one with
complexity exactly a2, ..., and at least one with complexity exactly an. Of
course, the round can also have problems with other complexities.

George has a poor imagination. It's easier for him to make some already prepared
problem simpler than to come up with a new one and prepare it. George is
magnificent at simplifying problems. He can simplify any already prepared
problem with complexity c to any positive integer complexity d (c ≥ d), by
changing limits on the input data.

However, nothing is so simple. George understood that even if he simplifies some
problems, he can run out of problems for a good round. That's why he decided to
find out the minimum number of problems he needs to come up with in addition to
the m he's prepared in order to make a good round. Note that George can come up
with a new problem of any complexity. Input

The first line contains two integers n and m (1 ≤ n, m ≤ 3000) — the minimal
number of problems in a good round and the number of problems George's prepared.
The second line contains space-separated integers a1, a2, ..., an
(1 ≤ a1 < a2 < ... < an ≤ 106) — the requirements for the complexity of the
problems in a good round. The third line contains space-separated integers
b1, b2, ..., bm (1 ≤ b1 ≤ b2... ≤ bm ≤ 106) — the complexities of the problems
prepared by George. Output

Print a single integer — the answer to the problem.
Examples
Input
Copy

3 5
1 2 3
1 2 2 3 3

Output
Copy

0

Input
Copy

3 5
1 2 3
1 1 1 1 1

Output
Copy

2

Input
Copy

3 1
2 3 4
1

Output
Copy

3

Note

In the first sample the set of the prepared problems meets the requirements for
a good round.

In the second sample, it is enough to come up with and prepare two problems with
complexities 2 and 3 to get a good round.

In the third sample it is very easy to get a good round if come up with and
prepare extra problems with complexities: 2, 3, 4.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<int> v1, v2;

int main() {
  int n, m, elm, p1, p2;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> elm;
    v1.push_back(elm);
  }
  for (int i = 0; i < m; ++i) {
    cin >> elm;
    v2.push_back(elm);
  }
  p1 = p2 = 0;
  while (p1 < n && p2 < m) {
    if (v2[p2] >= v1[p1]) {
      ++p1;
      ++p2;
    } else {
      ++p2;
    }
  }
  cout << n - p1 << endl;
  return 0;
}
