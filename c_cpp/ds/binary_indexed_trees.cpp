#include <iostream>
using namespace std;

/* https://stackoverflow.com/questions/7405438/why-if-n-n-n-then-n-is-a-power-of-2 */

/* https://cs.stackexchange.com/questions/10538/bit-what-is-the-intuition-behind-a-binary-indexed-tree-and-how-was-it-thought-a#:~:text=Intuitively%2C%20you%20can%20think%20of,of%20a%20standard%20array%20representation.&text=The%20idea%20is%20the%20following,find%20the%20node%20in%20question. */

/* flip the right most set bit to get the parent */
/* levels in BITree: 
    L1 -> all numbers where if we reset 1 right most set bit we get 0  
    L2 -> all numbers where if we reset 2 right most set bit we get 0
*/
void updateBIT(int *BITree, int n, int index, int val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}

int *constructBITree(int *arr, int *BITree, int n)
{
    for (int i = 0; i < n; i++)
    {
        updateBIT(BITree, n, i, arr[i]);
    }
    return BITree;
}

int getSum(int *BITree, int n, int index)
{
    int sum = 0;
    index = index + 1;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int BITree[n + 1];
    memset(BITree, 0, sizeof(int) * (n + 1));
    constructBITree(arr, BITree, n);

    int index;
    cin >> index;
    printf("%d", getSum(BITree, n, index));
    return 0;
}