#include <iostream>
#include <vector>
using namespace std;
/* patten: #solu_ending_at_i */

/* 
void * memset ( void * ptr, int value, size_t num );
Fill block of memory
Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char). 
*/
int longest_increasing_subsequence(int *arr, int n)
{
  if (n <= 1)
    return n;
  int dp[n];
  memset(dp, 0, sizeof(int) * n);
  dp[0] = 1;
  int m = 1, lm, il;
  for (int i = 1; i < n; i++)
  {
    lm = 1;
    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[j] <= arr[i])
      {
        il = dp[j] + 1;
        if (il > lm)
        {
          lm = il;
        }
      }
    }
    dp[i] = lm;
    if (lm > m)
    {
      m = lm;
    }
  }
  return m;
}

/* nlogn solution */
/* https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/ */
/* https://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/?ref=rp */
int get_right_bisect_idx_in_idx_list(int *arr, int n, int *idx_arr, int idx_arr_len, int val)
{
  // arr is sorted, index of number just greater than val
  int l = 0, h = idx_arr_len - 1, m;
  while (l < h)
  {
    /* we need to make sure that l is not replaced as that case is already handled */
    m = (l + h + 1) / 2;
    if (val <= arr[idx_arr[m]])
    {
      if (val > arr[idx_arr[m - 1]])
      {
        return m;
      }
      h = m - 1;
    }
    else if (val > arr[idx_arr[m]])
    {
      l = m + 1;
    }
  }
  return h;
}

int longest_increasing_subsequence_eff(int *arr, int n)
{
  if (n <= 1)
  {
    return n;
  }
  int last_elm_idx_acitive_lists[n], prev_idx[n];
  int l = 1, ceil_idx;
  last_elm_idx_acitive_lists[0] = 0;
  prev_idx[0] = -1;
  for (int i = 1; i < n; i++)
  {
    if (arr[i] == arr[last_elm_idx_acitive_lists[l - 1]])
    {
      continue;
    }
    else if (arr[i] > arr[last_elm_idx_acitive_lists[l - 1]])
    {
      prev_idx[i] = l - 1;
      last_elm_idx_acitive_lists[l] = i;
      l += 1;
    }
    else if (arr[i] <= arr[last_elm_idx_acitive_lists[0]])
    {
      prev_idx[i] = -1;
      last_elm_idx_acitive_lists[0] = i;
    }
    else
    {
      ceil_idx = get_right_bisect_idx_in_idx_list(arr, n, last_elm_idx_acitive_lists, l, arr[i]);
      last_elm_idx_acitive_lists[ceil_idx] = i;
      prev_idx[i] = last_elm_idx_acitive_lists[ceil_idx - 1];
    }
  }
  return l;
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << longest_increasing_subsequence_eff(arr, n);
  return 0;
}
