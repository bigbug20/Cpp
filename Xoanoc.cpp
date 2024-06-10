#include <iostream>
using namespace std;
int a[100][100];

void ham_xoan_oc(int n = 0, int m = 0)
{
    int count = 1;
    int top = 0, left = 0, bot = n - 1, right = m - 1;
    while (count <= n * m)
    {
        // duyệt từ trái sang phải
        for (int i = left; i <= right && count <= n * m; i++)
        {
            a[top][i] = count++;
        }
        top++;
        // duyệt từ trên xuống dưới
        for (int i = top; i <= bot && count <= n * m; i++)
        {
            a[i][right] = count++;
        }
        right--;
        // duyệt từ phải sang trái
        for (int i = right; i >= left && count <= n * m; i--)
        {
            a[bot][i] = count++;
        }
        bot--;
        // duyệt từ dưới lên trên
        for (int i = bot; i >= top && count <= n * m; i--)
        {
            a[i][left] = count++;
        }
        left++;
    }
}

void xuat_ham(int n, int m, int t)
{
    cout << "#" << t << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m;
        cin >> n >> m;
        ham_xoan_oc(n, m);
        xuat_ham(n, m, t);
    }
    return 0;
}
