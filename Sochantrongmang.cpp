#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];
    int loop;
    cin >> loop;
    for (int t = 0; t < loop; t++)
    {
        int h, w, m, n;
        cin >> h >> w >> m >> n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        int max = -100;
        for (int row = 0; row < m - h; row++)
        {
            for (int col = 0; col < n - w; col++)
            {
                int count = 0;
                for (int x = row; x < row + h; x++)
                {
                    for (int y = col; y < col + w; y++)
                    {
                        if (arr[x][y] % 2 == 0)
                        {
                            count += arr[x][y];
                        }
                    }
                }

                if (count > max)
                {
                    max = count;
                }
            }
        }
        cout << "#" << t + 1 << " " << max << endl;
    }

    return 0;
}