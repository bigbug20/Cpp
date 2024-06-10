#include <iostream>
using namespace std;

int m, n, hau, ma, tot;
// khai biến m,n số lượng hậu,tốt,mã
int nq[2][101], nk[2][101], arr[1001][1001];
// Khai báo 2 mảng lưu vị trí của queen and knight và mảng cục bộ
int totx, toty;
// Khai báo biến giá trị x,y của tốt
int dxq[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dyq[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// Khai báo 2 mảng lưu cách di chuyển của hậu
int dxk[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyk[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// Khai báo 2 mảng lưu cách di chuyển của mã
int count0;
// Khai báo biến đếm giá trị không

// Tạo hàm nhập hậu,mã,tốt
void nhap()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    // Tạo mảng cục bộ và cho tất cả = 0
    cin >> hau;
    if (hau > 0)
        for (int k = 0; k < hau; k++)
        {
            cin >> nq[0][k] >> nq[1][k];
            arr[nq[0][k] - 1][nq[1][k] - 1] = 1;
        }
    // Tạo vị trí các quân hậu gán bằng 1
    cin >> ma;
    if (ma > 0)
        for (int k = 0; k < ma; k++)
        {
            cin >> nk[0][k] >> nk[1][k];
            arr[nk[0][k] - 1][nk[1][k] - 1] = 2;
        }
    // Tạo vị trí quân mã gán bằng 2
    cin >> tot;
    if (tot > 0)
        for (int k = 0; k < tot; k++)
        {
            cin >> totx >> toty;
            arr[totx - 1][toty - 1] = 3;
        }
    // Tạo vị trí quân tốt gán bằng 3
}

bool check(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return false;
    return true;
}

void cal()
{
    count0 = 0;
    // Tính nước đi của hậu
    for (int i = 0; i < hau; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int nxq = nq[0][i] - 1 + dxq[j];
            int nyq = nq[1][i] - 1 + dyq[j];
            while (check(nxq, nyq) && (arr[nxq][nyq] == 0 || arr[nxq][nyq] == -1))
            {
                arr[nxq][nyq] = -1;
                nxq += dxq[j];
                nyq += dyq[j];
            }
        }
    }

    // Tính nước đi của quân mã
    for (int i = 0; i < ma; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int nxk = nk[0][i] - 1 + dxk[j];
            int nyk = nk[1][i] - 1 + dyk[j];
            if (check(nxk, nyk) && (arr[nxk][nyk] == 0 || arr[nxk][nyk] == -1))
            {
                arr[nxk][nyk] = -1;
            }
        }
    }
    // Đếm số ô còn lại
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                count0++;
        }
    }
}

int main()
{
    int t = 1;
    while (true)
    {
        cin >> m >> n;
        if (n == 0 || m == 0)
            break;
        nhap();
        cal();
        cout << "Board " << t << " has " << count0 << " safe squares." << endl;
        t++;
    }
    return 0;
}