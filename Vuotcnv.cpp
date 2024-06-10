#include <iostream>
using namespace std;

int T, n;
int arr[101][101];
int vi_tri[2][10001];
int xxp, yxp;
int sum, xmin, ymin;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void nhap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

bool check(int i, int j)
{
    if (i < n && i >= 0 && j < n && j >= 0)
        return true;
    return false;
}

void nhay(int t)
{
    int min = 10000;
    int count = 0;
    for (int k = 0; k < 8; k++)
    {
        int max = arr[xxp][yxp];
        int nx = xxp + dx[k];
        int ny = yxp + dy[k];
        if (check(nx, ny) && arr[nx][ny] > max && arr[nx][ny] < min)
        {
            min = arr[nx][ny];
            xmin = nx;
            ymin = ny;
            count++;
        }
    }
    if (count != 0)
    {
        xxp = xmin;
        yxp = ymin;
        sum++;
        nhay(t);
    }
    else
        cout << "#" << t << " " << sum << endl;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> xxp >> yxp;
        sum = 0;
        nhap();
        nhay(t);
    }
    return 0;
}