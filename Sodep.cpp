#include <iostream>
#include <string>
using namespace std;

int T, n, m;
int so[1001];
int x, y;

int dem()
{
    int count = 0;
    for (int i = x; i <= y; i++)
    {
        // Để không làm thay đổi i, ta dùng biến tmp để lấy giá trị của i xử lý

        int tmp = i;
        int dem = 0;
        while (tmp > 0)
        {
            int digit = tmp % 10;

            for (int k = 0; k < n; k++)
            {
                if (so[k] == digit)
                    dem++;
            }
            tmp /= 10;
        }
        if (dem >= m)
            count++;
    }
    return count;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> so[i];
        }
        cin >> x >> y;
        int count = dem();
        cout << "#" << t << " " << count << endl;
    }
    return 0;
}