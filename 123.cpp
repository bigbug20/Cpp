#include <iostream>
using namespace std;

int T, n, q;
int arr[101][11];

void loai(int i)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = j; k < n; k++)
        {
            if ((arr[i][j] == 1 && arr[i][k] == 2) || (arr[i][j] == 3 && arr[i][k] == 1) || (arr[i][j] == 2 && arr[i][k] == 3))
                for (int m = 0; m < q; m++)
                {
                    arr[m][j] = 0;
                }
            else if ((arr[i][j] == 2 && arr[i][k] == 1) || (arr[i][j] == 1 && arr[i][k] == 3) || (arr[i][j] == 3 && arr[i][k] == 2))
                for (int m = 0; m < q; m++)
                {
                    arr[m][k] = 0;
                }
        }
    }
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> q;
        for (int i = 0; i < q; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < q; i++)
        {
            int dem1 = 0;
            int dem2 = 0;
            int dem3 = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1)
                    dem1++;
                else if (arr[i][j] == 2)
                    dem2++;
                else if (arr[i][j] == 3)
                    dem3++;
            }
            if ((dem1 == 0 && dem2 != 0 && dem3 != 0) || (dem1 != 0 && dem2 == 0 && dem3 != 0) || (dem1 != 0 && dem2 != 0 && dem3 == 0))
                loai(i);
        }
        cout << "#" << t << " ";

        for (int j = 0; j < n; j++)
        {
            int i = 0;
            if (arr[i][j] != 0)
                cout << j + 1 << " ";
        }

        cout << endl;
    }

    return 0;
}