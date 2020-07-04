#include <iostream>
#define Z(x, l) for (int x = 1; x <= l; x++)
using namespace std;
int main()
{
  int n, l, m;
  cin >> n;
  while (n--)
  {
    cin >> l;
    int a[l + 1][l + 1] = {};
    Z(i, l)
        Z(j, i) cin >> a[i][j];
    m = 0;
    Z(i, l)
    Z(j, i) m = max(m, a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]));
    cout << m << "\n";
  }
  return 0;
}