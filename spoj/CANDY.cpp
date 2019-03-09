#include < iostream > 
#include < vector > 
#include < limits.h >
using namespace std;
int count = 0;

void move(int a[], int i, int j) {
  a[i]--;
  a[j]++;
  count++;
}

void merge(int a[], int l, int m, int h) {
  int s1 = m - l + 2, s2 = h - m + 1;
  int a1[s1], a2[s2];
  for (int i = 0; i < s1 - 1; i++) {
    a1[i] = a[l + i];
  }
  a1[s1 - 1] = INT_MIN;
  for (int i = 0; i < s2 - 1; i++) {
    a2[i] = a[m + 1 + i];
  }
  a2[s2 - 1] = INT_MIN;
  int p = 0, q = 0;
  for (int k = l; k <= h; k++) {
    if (a1[p] > a2[q]) {
      a[k] = a1[p];
      p++;
    } else {
      a[k] = a2[q];
      q++;
    }
  }

}

void mergesort(int a[], int l, int h) {
  if (l >= h) return;
  else {
    int mid = (l + h) / 2;
    mergesort(a, l, mid);
    mergesort(a, mid + 1, h);
    merge(a, l, mid, h);
  }
}

int main() {
  vector < int > output;

  int sz;
  cin >> sz;
  while (sz != (-1)) {
    int arr[sz];
    int sum = 0;
    for (int i = 0; i < sz; i++) {
      cin >> arr[i];
      sum = sum + arr[i];
    }
    int avg = (sum / sz);
    if ((sz * avg) == sum) {
      mergesort(arr, 0, sz - 1);
      int p = 0, q = sz - 1;
      while (p < q) {
        if (arr[p] != avg && arr[q] != avg)
          move(arr, p, q);
        if (arr[p] == avg) p++;
        if (arr[q] == avg) q--;
      }
      output.push_back(count);
      count = 0;
    } else {
      output.push_back(-1);
    }
    cin >> sz;
  }
  for (int i = 0; i < output.size(); i++)
    cout << "\n" << output[i];
  return 0;
}