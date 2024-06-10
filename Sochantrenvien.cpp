#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];
    int so_luong_test;
    cin >> so_luong_test;
    for (int t = 0; t < so_luong_test; t++)
    {
        int chieu_cao, chieu_rong, so_hang, so_cot;
        cin >> chieu_cao >> chieu_rong >> so_hang >> so_cot;
        for (int i = 0; i < so_hang; i++)
        {
            for (int j = 0; j < so_cot; j++)
            {
                cin >> arr[i][j];
            }
        }
        int max_tong = -100;

        // Duyệt qua tất cả các góc trên bên trái của hình chữ nhật h x w
        for (int hang = 0; hang <= so_hang - chieu_cao; hang++)
        {
            for (int cot = 0; cot <= so_cot - chieu_rong; cot++)
            {
                int tong = 0;
                // Viền trên
                for (int x = cot; x < cot + chieu_rong; x++)
                {
                    if (arr[hang][x] % 2 == 0)
                    {
                        tong += arr[hang][x];
                    }
                }
                // Viền dưới
                for (int x = cot; x < cot + chieu_rong; x++)
                {
                    if (arr[hang + chieu_cao - 1][x] % 2 == 0)
                    {
                        tong += arr[hang + chieu_cao - 1][x];
                    }
                }
                // Viền trái
                for (int y = hang + 1; y < hang + chieu_cao - 1; y++)
                {
                    if (arr[y][cot] % 2 == 0)
                    {
                        tong += arr[y][cot];
                    }
                }
                // Viền phải
                for (int y = hang + 1; y < hang + chieu_cao - 1; y++)
                {
                    if (arr[y][cot + chieu_rong - 1] % 2 == 0)
                    {
                        tong += arr[y][cot + chieu_rong - 1];
                    }
                }
                if (tong > max_tong)
                {
                    max_tong = tong;
                }
            }
        }
        cout << "#" << t + 1 << " " << max_tong << endl;
    }

    return 0;
}
