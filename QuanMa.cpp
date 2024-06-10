#include <iostream>
using namespace std;

int dxk[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyk[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// Khai báo 2 mảng lưu cách di chuyển của mã
int nk[3][10000001], arr[1001][1001];
// Khai báo mảng lưu vị trí quân mã và số lượng ăn, mảng cục bộ
int n, ma, tot, no;
// Khai báo kích thước mảng, số lượng quân mã, quân tốt và quần chặn no
int totx, toty, nox, noy;
// Khai báo tọa độ quân tot và quân no
int x_max, y_max;
// Khai báo biến lưu giá trị vị trí quân mã ăn nhiều quân nhẩt

int an_max = -100;
void input()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int k = 0; k < ma; k++)
    {
        cin >> nk[0][k] >> nk[1][k];
        nk[2][k] = 0;
        arr[nk[0][k]][nk[1][k]] = 3;
    }
    for (int k = 0; k < tot; k++)
    {
        cin >> totx >> toty;
        arr[totx][toty] = 2;
    }
    for (int k = 0; k < no; k++)
    {
        cin >> nox >> noy;
        arr[nox][noy] = 1;
    }
}

bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}

void calc()
{
    for (int i = 0; i < ma; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int nxk = nk[0][i] + dxk[j];
            int nyk = nk[1][i] + dyk[j];
            if (check(nxk, nyk) && (arr[nxk][nyk] == 2 || arr[nxk][nyk] == 3))
            {
                nk[2][i]++;
            }
        }
        if (nk[2][i] > an_max)
        {
            an_max = nk[2][i];
            x_max = nk[0][i];
            y_max = nk[1][i];
        }
    }
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        an_max = -100;
        cin >> n >> ma >> tot >> no;
        input();
        calc();
        cout << "#" << t << " " << x_max << " " << y_max << " " << an_max << endl;
    }
}