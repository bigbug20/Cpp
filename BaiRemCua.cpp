#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    char arr[502][502];
    int res[5];

    for (int t = 0; t < T; t++)
    {
        int m, n;
        cin >> m >> n;

        for (int i = 0; i < 5; i++)
        {
            res[i] = 0;
        }

        for (int i = 0; i < 5 * m + 1; i++)
        {
            for (int j = 0; j < 5 * n + 1; j++)
            {
                cin >> arr[i][j];
            }
        }

        // tinh toan dem so luong rem cua da su dung

        for (int i = 1; i < 5 * m + 1; i += 5)
        {
            for (int j = 1; j < 5 * n + 1; j += 5)
            {
                int count = 0;
                for (int k = i; k < i + 4; k++)
                {
                    if (arr[k][j] == '*')
                        count++;
                }
                res[count]++;
            }
        }
        // in ra kq

        cout << "#" << t + 1;
        for (int i = 0; i < 5; i++)
        {
            cout << " " << res[i];
        }
        cout << endl;
    }
    return 0;
}