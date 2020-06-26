#include <iostream>
using namespace std;

void createST(int *arr, int *st, int n)
{
    for (int i = 0; i < n; i++)
    {
        st[i + n] = arr[0];
    }
    for (int j = n - 1; j > 0; j--)
    {
        st[j] = st[j << 1] + st[j << 1 | 1];
    }
}

void updateST(int *st, int n, int idx, int new_val)
{
    st[n + idx] = new_val;
    int i = n + idx;
    for (; i > 0; i >>= 1)
    {
        st[i >> 1] = st[i] + st[i ^ 1];
    }
}

int queryST(int *st, int n, int l, int r)
{
    int res = 0;
    /* visualise value capture keeping in mind including l excluding r */
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res += st[l++];
        }
        if (r & 1)
        {
            res += st[--r];
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    int st[2 * n];
    createST(arr, st, n);

    //update segment tree
    int idx, new_val;
    cin >> idx >> new_val;
    updateST(st, n, idx, new_val);

    //query segment tree [l, r)
    int res = 0;
    int l, r; // visualise value capture keeping in mind including l excluding r
    cin >> l >> r;
    printf("%d", queryST(st, n, l, r));

    return 0;
}
