#include <iostream>

using namespace std;

// toa do x huong di cua quan hau
int dxq[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
// toa do y huong di cua quan hau
int dyq[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

// toa do x huong di cua quan ma
int dxk[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
// toa do y huong di cua quan ma
int dyk[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

// mang ma tran
int arr[1002][1002];
// kich thuoc cua mang
int n, m;
// so luong quan hau, quan ma, quan tot
int h, ma, to;
// mang luu toa do quan hau
int nq[2][101];
// mang luu toa do quan ma
int nk[2][101];

// bien dem so luong
int count1;

void input()
{
    // mang toan bo luu la 0, quan hau luu la 1, quan ma la 2, tot la 3, cac nuoc quan hau hoac quan ma da di qua la -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }
    // nhap Quan hau
    cin >> h;
    if (h > 0)
    {
        for (int k = 0; k < h; k++)
        {
            cin >> nq[0][k] >> nq[1][k];
            arr[nq[0][k] - 1][nq[1][k] - 1] = 1;
        }
    }
    // nhap Quan ma
    cin >> ma;
    if (ma > 0)
    {
        for (int k = 0; k < ma; k++)
        {
            cin >> nk[0][k] >> nk[1][k];
            arr[nk[0][k] - 1][nk[1][k] - 1] = 2;
        }
    }
    // nhap Quan tot
    cin >> to;
    if (to > 0)
    {
        for (int k = 0; k < to; k++)
        {
            int tox, toy;
            cin >> tox >> toy;
            arr[tox - 1][toy - 1] = 3;
        }
    }
}

bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}

void calc()
{

    count1 = 0;
    // Nuoc di cua quan hau
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int x = nq[0][i] - 1 + dxq[j];
            int y = nq[1][i] - 1 + dyq[j];
            while (check(x, y) && arr[x][y] == 0 || arr[x][y] == -1)
            {
                arr[x][y] = -1;
                x += dxq[j];
                y += dyq[j];
            }
        }
    }

    // Nuoc di cua quan ma
    for (int i = 0; i < ma; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int x = nk[0][i] - 1 + dxk[j];
            int y = nk[1][i] - 1 + dyk[j];
            if (check(x, y) && arr[x][y] == 0 || arr[x][y] == -1)
            {
                arr[x][y] = -1;
                x += dxk[j];
                y += dyk[j];
            }
        }
    }

    // dem so luong o ma quan hau va quan ma ko an duoc

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                count1++;
        }
    }
}

int main()
{
    int t = 1;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 || m == 0)
            break;
        input();
        calc();
        cout << "Board " << t << " has " << count1 << " safe squares." << endl;
        t++;
    }
    return 0;
}