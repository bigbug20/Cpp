#include <iostream>
using namespace std;

int check_type(char c)
{
    int range = 0;
    if (c == 'A')
    {
        range = 1;
    }
    else if (c == 'B')
    {
        range = 2;
    }
    else if (c == 'C')
    {
        range = 3;
    }
    return range;
}

int main()
{
    char arr[100][100];
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int m, n;
        cin >> m >> n;
        int cout_H = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'H')
                {
                    cout_H++;
                }
            }
        }
        int min_H = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int check = check_type(arr[i][j]);
                if (check != 0)
                {
                    for (int x = i - check; x <= i + check; x++)
                    {
                        if (x >= 0 && x < m && arr[x][j] == 'H')
                        {
                            arr[x][j] = 'X';
                            min_H++;
                        }
                    }
                    for (int y = j - check; y <= j + check; y++)
                    {
                        if (y >= 0 && y < n && arr[i][y] == 'H')
                        {
                            arr[i][y] = 'X';
                            min_H++;
                        }
                    }
                }
            }
        }
        cout_H -= min_H;
        cout << "#" << t + 1 << " " << cout_H << endl;
    }
    return 0;
}
