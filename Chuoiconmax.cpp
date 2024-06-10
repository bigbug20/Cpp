#include <iostream>
using namespace std;

int T;
char arr[1001];

bool check(int i, int j)
{
    while (i < j)
    {
        if (arr[i] != arr[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> arr;
        int len = 0, max = -100;
        while (arr[len] != '\0')
        {
            len++;
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                if (check(i, j))
                {
                    int count = j - i + 1;
                    if (count > max)
                        max = count;
                }
            }
        }
        cout << "#" << t << " " << max << endl;
    }
    return 0;
}