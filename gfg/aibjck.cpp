#include <iostream>
using namespace std;
int find_aibjck_count(string s)
{
    int a = 0, b = 0, c = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            a += (2 * a + 1);
        }
        else if (s[i] == 'b')
        {
            b += (2 * b + a);
        }
        else if (s[i] == 'c')
        {
            c += (2 * c + b);
        }
    }
    return c;
}

int main()
{
    //code
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        cout << find_aibjck_count(s) << "\n";
    }
    return 0;
}