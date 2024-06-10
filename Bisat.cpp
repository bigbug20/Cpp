#include <iostream>
using namespace std;

int arr[101][101], lenh[11];
int n, m, k, T, count;
int ixp[100], jxp[100];  // Mảng tĩnh để lưu vị trí của số 2
int num_start_positions; // Biến để đếm số vị trí bắt đầu

void nhap()
{
    num_start_positions = 0;
    count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                ixp[num_start_positions] = i;
                jxp[num_start_positions] = j;
                num_start_positions++;
                count++;
            }
        }
    }
}

void thuc_hien_lenh(int &ix, int &j, int lenh)
// truyền tham chiếu để có thể thay đổi giá trị cục bộ khi thực hiện lệnh
{
    if (lenh == 1)
    {
        for (int i = ix - 1; i >= 0; i--)
        {
            ix = i;
            if (arr[i][j] == 0)
            {
                arr[i][j] = -1;
                count++;
            }
            else if (arr[i][j] == 1)
            {
                ix = i + 1;
                break;
            }
        }
    }
    else if (lenh == 2)
    {
        for (int i = j + 1; i < m; i++)
        {
            j = i;
            if (arr[ix][i] == 0)
            {
                arr[ix][i] = -1;
                count++;
            }
            else if (arr[ix][i] == 1)
            {
                j = i - 1;
                break;
            }
        }
    }
    else if (lenh == 3)
    {
        for (int i = ix + 1; i < n; i++)
        {
            ix = i;
            if (arr[i][j] == 0)
            {
                arr[i][j] = -1;
                count++;
            }
            else if (arr[i][j] == 1)
            {
                ix = i - 1;
                break;
            }
        }
    }
    else if (lenh == 4)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            j = i;
            if (arr[ix][i] == 0)
            {
                arr[ix][i] = -1;
                count++;
            }
            else if (arr[ix][i] == 1)
            {
                j = i + 1;
                break;
            }
        }
    }
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> lenh[i];
        }
        nhap();
        for (int pos = 0; pos < num_start_positions; pos++)
        {
            int ix = ixp[pos];
            int j = jxp[pos];
            for (int i = 0; i < k; i++)
            {
                thuc_hien_lenh(ix, j, lenh[i]);
            }
        }
        cout << "#" << t << " " << count << endl;
    }
    return 0;
}
