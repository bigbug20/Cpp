#include <iostream>
using namespace std;

int T, n;
int arr[102][102];
int x_xp, y_xp;

void xu_ly()
{
    x_xp = 0;
    y_xp = n / 2;
    arr[x_xp][y_xp] = 1;
    int cnt = 1;
    while (cnt < n * n)
    {
        cnt++;
        int x_xpt = (x_xp - 1 + n) % n; // sử dụng phép chia lấy dư để quay vòng
        int y_xpt = (y_xp + 1) % n;

        if (arr[x_xpt][y_xpt] != 0)
        {
            x_xpt = (x_xp + 1) % n;
            y_xpt = y_xp;
        }

        arr[x_xpt][y_xpt] = cnt;
        x_xp = x_xpt;
        y_xp = y_xpt;
    }
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = 0;
            }
        }
        xu_ly();
        cout << "#" << t << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
