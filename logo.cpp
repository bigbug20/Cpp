#include <iostream>
using namespace std;

int T, n;
int arr[33][33];
int middle;
int res = 1;
int dem_1 = 0;

void nhap()
{
    dem_1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                dem_1++;
        }
    }
}

bool duyet()
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != arr[n - i - 1][j])
                return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            if (arr[i][j] != arr[i][n - 1 - j])
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        nhap();
        if (dem_1 == 0)
            cout << "#" << t << " " << "NO" << endl;
        else
        {
            cout << "#" << t << " " << (duyet() ? "YES" : "NO") << endl;
        }
    }
    return 0;
}